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
for k = 1:N
 x_state_k = add_usys_d.matrices.A*x_state_k + add_usys_d.matrices.B*U_x(k)+add_usys_d.matrices.E*W_x(k);
 Y_x = [Y_x;add_usys_d.matrices.C*x_state_k];
end

F_x = [Y_x <= Y_x_Limit, U_x_bounds(1) <= U_x <= U_x_bounds(2)];
objective_x = norm(Y_x-1,norm_type)*Q + norm(U_x,norm_type)*R;
G_x = [W_x_bounds(1) <= W_x <= W_x_bounds(2)];

[Frobust_x,h_x] = robustify(F_x + G_x, objective_x, [], W_x);
[sol_x_mp,diagnostics_x,aux_x,ValueFunction_x,Optimizer_x] = solvemp(Frobust_x,h_x,[],x_state,U_x(1));

disp('### Multiparametric Robust MPC computed');