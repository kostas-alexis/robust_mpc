function u_ctrl = robustmpc_getInput(sol_x_mp, x_state_value)
%
%   get control action from the explicit robust mpc computed using YALMIP
%
%   Syntax:
%   u_ctrl = robustmpc_getInput(sol_x_mp, x_state_value)
%
%   Inputs:
%   sol_x_mp        : Multiparametric Robust MPC explicit solution
%   x_state_value   : value of the state vector
%
%   Outputs:
%   u_ctrl          : control action
%
%   Authors: Kostas Alexis (konstantinos.alexis@mavt.ethz.ch)


[i,j] = isinside(sol_x_mp{1}.Pn, x_state_value);
u_ctrl = sol_x_mp{1}.Fi{j}*x_state_value + sol_x_mp{1}.Gi{j}

end