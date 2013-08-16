function [y,t] = simulate_Multiparametric_Approximate_ClosedLoop_MinMax(add_usys_d,sol_x_mp,x_state_init,time_sec)
%
%   Simulate Closed Loop response of Approximate Closed Loop MinMax
%   solution, computed using Multiparametric methods:
%
%   Inputs:
%   add_usys_d      : state space additive uncertainty sys in Discrete time
%   sol_x_mp        : Multiparametric solution of the controller
%   x_state_init    : initial condition
%
%   Outputs:
%   y               : output
%   

t = 0:Ts:time_sec;
x_state_k = x_state_init;

ops = sdpsettings;
for i = 1:length(time_sec)
    u_ctrl = robustmpc_getInput(sol_x_mp, x_state_k);
    x_state_k = [x_state_k add_usys_d.matrices.A*x_state_k(:,end) + add_usys_d.matrices.B*double(u_ctrl) + add_usys_d.matrices.E*(-1+2*rand(1))];
    y(i,:) = double(x_state_k);
end

close all;
num_outs = min(size(add_usys_d.matrices.C);

for i = 1:num_outs
    figure(i)
    plot(t,y(:,1)); grid on;
    xlabel('Time (s)'); ylabel(['y(' num2str(i) ')']);
end

end

end