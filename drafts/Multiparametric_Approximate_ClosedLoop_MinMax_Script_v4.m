%%  Multiparametric Approximate Closed-Loop MinMax
%   runs as script
%
%   Vriables that have to be defined before:
%   add_usys_d  : the system of additive uncertainty
%   x_state     : x_state sdp var
%   Y_x_Limit   : limit of output
%   U_x_bounds  : Bounds of Input
%   W_x_bounds  : Bounds of disturbance
%   Q           : Q Penalizing matrix
%   R           : R Penalizing matrix
%   N           : Prediction horizon
%   norm_type   : norm type
%
%   A multiparametric solution to the approximate closed-loop MinMax 
%   solution.
%
%   Code based on: YALMIP Wiki (users.isy.liu.se)
%
%   Authors: Kostas Alexis (konstantinos.alexis@mavt.ethz.ch)
%

W_x = sdpvar(N,1);
x_state = sdpvar(length(x_state),1);

%% We create a causal feedback U = LW + V and derive the predicted states.  
V_x = sdpvar(N,1);
L_x = sdpvar(N,N,'full').*(tril(ones(N))-eye(N));

U_x = L_x*W_x + V_x;

Y_x = [];
F_x = [];
x_state_k = x_state;
objective_x = 0;
Frobust_x = [];
h_x =0;
for k = 1:N
	x_state_k = add_usys_d.matrices.A*x_state_k + add_usys_d.matrices.B*U_x(k)+add_usys_d.matrices.E*W_x(k);
	Y_x = [add_usys_d.matrices.C*x_state_k];
    objective_x = objective_x + norm((Q*(Y_x-Y_ref)),norm_type) + norm(R*U_x(k),norm_type);
    objective_x_cur = norm((Q*(Y_x-Y_ref)),norm_type) + norm(R*U_x(k),norm_type);
    F_x_cur = [-Y_x_Limit_orig' <= Y_x <= Y_x_Limit_orig', U_x_bounds(1) <= U_x(k) <= U_x_bounds(2)];
    F_x = [F_x , -Y_x_Limit_orig' <= Y_x <= Y_x_Limit_orig', U_x_bounds(1) <= U_x(k) <= U_x_bounds(2)];
    [Frobust_x_new, h_x_new] = robustify(F_x_cur + G_x, objective_x_cur, [], W_x);
    Frobust_x = [Frobust_x, Frobust_x_new];
%     [Frobust_x_new,h_x_new] = robustify(F_x + G_x, objective_x, [], W_x);
%     Frobust_x = [Frobust_x, Frobust_x_new];
    h_x = h_x + h_x_new;
end
%%
%F_x = [-Y_x_Limit <= Y_x <= Y_x_Limit, U_x_bounds(1) <= U_x <= U_x_bounds(2)];

%   Fix the size of Y ref for horizon
N_y = length(Y_ref);
size_B = size(add_usys_d.matrices.B); N_u = size_B(2);
clear Y_ref_hor
for kk = 1:N
    Y_ref_hor(((kk-1)*N_y+1):(kk*N_y)) = Y_ref;
end

%   Fix the size of Q,R for horizon
clear Q_hor R_hor
Q_hor(1:(N*N_y),1:(N*N_y)) = 0;
R_hor(1:(N*N_u),1:(N*N_u)) = 0;

for kk = 1:N
    Q_hor(((kk-1)*N_y+1):(kk*N_y),((kk-1)*N_y+1):(kk*N_y)) = Q;
    R_hor(((kk-1)*N_u+1):(kk*N_u),((kk-1)*N_u+1):(kk*N_u)) = R;
end
objective_x = norm((Q_hor*(Y_x-Y_ref_hor')),norm_type) + norm(R_hor*U_x,norm_type);
%%
G_x = [W_x_bounds(1) <= W_x <= W_x_bounds(2)];

[Frobust_x,h_x] = robustify(F_x + G_x, objective_x, [], W_x);
%[sol_x_mp,diagnostics_x,aux_x,ValueFunction_x,Optimizer_x] = solvemp(Frobust_x,h_x,[],x_state,U_x(1));
%%
[sol_x_mp,diagnostics_x,aux_x,ValueFunction_x,Optimizer_x] = solvemp(Frobust_x,h_x,[],Y_x,U_x(1));
%%
disp('### Multiparametric Robust MPC computed');
