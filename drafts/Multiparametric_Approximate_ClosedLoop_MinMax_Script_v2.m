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

%We create a causal feedback U = LW + V and derive the predicted states.  
V_x = sdpvar(N,1);
L_x = sdpvar(N,N,'full').*(tril(ones(N))-eye(N));

U_x = L_x*W_x + V_x;

Y_x = [];
x_state_k = x_state;

F_x = [];
Y_x_Limit = [Inf 1 1 1]';
objective_x = 0;
%x_state_k = x_state_init;
for k = 1:N
    x_state = add_usys_d.matrices.A*x_state + add_usys_d.matrices.B*U_x(k);
    objective_x = objective_x + norm(1*x_state,1) + norm(.1*U_x(k),1);
    F_x = [F_x, x_state <= Y_x_Limit, x_state >= -Y_x_Limit, U_x_bounds(1) <= U_x(k) <= U_x_bounds(2)];
end

% %%
% constraints = [];
% objective = 0;
% x = x0;
% for k = 1:N
%  x = A*x + B*u{k};
%  objective = objective + norm(Q*x,1) + norm(R*u{k},1);
%  constraints = [constraints, -1 <= u{k}<= 1, -5<=x<=5];
% end

% %%
% for k = 1:N
%  x_state_k = add_usys_d.matrices.A*x_state_k + add_usys_d.matrices.B*U_x(k)+add_usys_d.matrices.E*W_x(k);
%  Y_x{k} = [Y_x{k};add_usys_d.matrices.C*x_state_k];
%  objective_x = objective_x + norm((10*(Y_x{k})),norm_type) + norm(.01*U_x(k),norm_type);
%  F_x = [ Y_x{k} <= Y_x_Limit, Y_x{k} >= -Y_x_Limit, U_x_bounds(1) <= U_x(k) <= U_x_bounds(2)];
% 
% end

% F_x = [Y_x <= Y_x_Limit, Y_x >= -Y_x_Limit, U_x_bounds(1) <= U_x <= U_x_bounds(2)];
% objective_x = norm(([Q 0*Q; 0*Q Q]*(Y_x)),norm_type) + norm(R*U_x,norm_type);
%objective_x = norm(((Y_x-Y_ref)')*[Q 0*Q; 0*Q Q],norm_type) + norm(U_x*[R 0*R; 0*R R],norm_type)*R;
% objective_x = ((Y_x-Y_ref)')*[Q 0*Q; 0*Q Q]*(Y_x-Y_ref) + (U_x')*[R 0*R; 0*R R]*U_x;
% objective_x = ((Y_x-Y_ref)')*[1 .01 .01 .01 1 .01 .01 .01]' + (U_x')*[.001 .001]';

G_x = [W_x_bounds(1) <= W_x <= W_x_bounds(2)];

[Frobust_x,h_x] = robustify(F_x + G_x, objective_x, [], W_x);
%[sol_x_mp,diagnostics_x,aux_x,ValueFunction_x,Optimizer_x] = solvemp(Frobust_x,h_x,[],x_state);
%[sol_x_mp,diagnostics_x,aux_x,ValueFunction_x,Optimizer_x] = solvemp(Frobust_x,h_x,[],x_state,U_x(1));
[sol_x_mp,diagnostics_x,aux_x,ValueFunction_x,Optimizer_x] = solvemp(Frobust_x,h_x,[],x_state);


disp('### Multiparametric Robust MPC computed');
