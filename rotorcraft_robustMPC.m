%%  Rotorcraft Robust MPC Control Design
%
%   Authors: Kostas Alexis (konstantinos.alexis@mavt.ethz.ch)

addpath('C:\Users\Kostas\Documents\MATLAB\Control\MPT3\')
%addpath('C:\Users\Kostas\Documents\MATLAB\Control\Robust MPC\')
addpath(genpath('C:\Users\Kostas\Documents\GitHub\Robust_mpc\'))
%%  Step 1: Assume some second order closed loop attitude dynamics
disp('### Define the Attitude Subsystem Closed-Loop Dynamics');

A_rp = [0 1; 0 -10];
B_rp = [0; 10];
C_rp = eye(2);
D_rp = zeros(2,1);

A_y = [0 1; 0 -2;];
B_y = [0; 2];
C_y = eye(2);
D_y = zeros(2,1);

sys_rp = ss(A_rp,B_rp,C_rp,D_rp);
sys_y = ss(A_y,B_y,C_y,D_y);

close all
subplot(2,1,1); step(sys_rp(2,1)); grid on;
subplot(2,1,2); step(sys_y(2,1)); grid on;

%%  Step 2: Assume a first order thrust model
disp('### Define Thrust Model');

A_t = -1;
B_t = 1;
C_t = 1;
D_t = 0;

sys_t = ss(A_t,B_t,C_t,D_t);


%%  Cascade the attitude - thrust dynamics with the translational dynamics
disp('### Cascade the Attitude-Thrust Dynamics with the Translational Dynamics');
disp('!!! -> sys_x, sys_y WE ASSUME WE ONLY MEASURE VELOCITY');

m = 1.0;
g = 9.8065; % m/s^2

A_x =  [0   1   0   0;
        0   0   g   0;
        0   0   A_rp(1,1)   A_rp(1,2);
        0   0   A_rp(2,1)   A_rp(2,2);];
B_x = [ 0; 0; B_rp(1); B_rp(2) ];
C_x = eye(4); C_x(1,1) = 0; C_x(3,3) = 0; C_x(4,4) = 0;
C_x = eye(4);
D_x = zeros(4,1);

A_y = A_x;
A_y(2,3) = - A_y(2,3);
B_y = B_x;
C_y = C_x;
D_y = D_x;

A_z = [0 1 0;
       0 0 (1/m);
       0 0 A_t(1);];
B_z = [0; 0; B_t(1);];
C_z = eye(3); 
D_z = zeros(3,1);

sys_x = ss(A_x,B_x,C_x,D_x);
sys_y = ss(A_y,B_y,C_y,D_y);
sys_z = ss(A_z,B_z,C_z,D_z);

%%  Discretize
disp('### Discretize')
Ts = 0.02;

sys_x_d = c2d(sys_x,Ts,'zoh');
sys_y_d = c2d(sys_y,Ts,'zoh');
sys_z_d = c2d(sys_z,Ts,'zoh');

%%  Define Additive Uncertain Model
E_x = 0.1*B_x;
add_usys_d = add_uss(A_x,B_x,C_x,D_x,E_x,Ts)

time_vec = 0:0.01:100;
u_inp = 10*sin(time_vec);
[y,t] = lsim_addusys(add_usys_d,[-0.5 0.5],u,t);
%%  Open-Loop MinMax Solution
norm_type = 1;
W_x_bounds = [-0.5 0.5];
N = 5; 

Y_x_Limit = 1;
% Y_x_Limit = 1*ones(min(size(add_usys_d.matrices.C))*N,1);
U_x_bounds = [-10 10];
x_state = sdpvar(length(add_usys_d.matrices.A),1);

Q = 10;
R = 0.1;

disp('Open-Loop MiniMax Solution');
Simul_Steps = 100;
x_state_k = OpenLoop_MinMax_Solution(add_usys_d,x_state,Y_x_Limit,U_x_bounds,W_x_bounds,Q,R,N,norm_type,Simul_Steps);
close all
plot(x_state_k(2,1:end))

%%  Approximate Closed Loop MinMax Solution
    
norm_type = 1;
W_x_bounds = [-0.5 0.5];
Y_x_Limit = 1;
% Y_x_Limit = 1*ones(min(size(add_usys_d.matrices.C))*N,1);

U_x_bounds = [-100 100];

Q = 10;
R = 0.1;

x_state_k = Approximate_ClosedLoop_MinMax_Solution(add_usys_d,x_state,Y_x_Limit,U_x_bounds,W_x_bounds,Q,R,N,norm_type,Simul_Steps)
hold on
plot(x_state_k(2,1:end),'r')

%%  MultiParametric Approximate Closed Loop MinMax Solution

norm_type = 1;
W_x_bounds = [-0.5 0.5];
Y_x_Limit = 1;
% Y_x_Limit = 1*ones(min(size(add_usys_d.matrices.C))*N,1);

U_x_bounds = [-100 100];

Q = 10;
R = 0.1;

run Multiparametric_Approximate_ClosedLoop_MinMax_Script

beep 

flag_sim = input('Show Simulation? [0/1]');
if(flag_sim == 1)
    x_state_init = zeros(length(x_state),1);
    time_sec = 10; % 10 secs
    time_sec = input('how long [s]?');
    [y,t] = simulate_Multiparametric_Approximate_ClosedLoop_MinMax(add_usys_d,sol_x_mp,x_state_init,time_sec)
end

%%  Alternative Methods and plots
assign(x_state,[-0.09 -0.0 -.01 -0.05]')
double(Optimizer_x)

plot(ValueFunction_x)
figure
plot(Optimizer_x(1));

%%  Dynamic Programming Exact Solution

norm_type = 1;
W_x_bounds = [-0.5 0.5];
Y_x_Limit = 1;
U_x_bounds = [-100 100];

X_expl_bounds = [-100 100];

sol_x = DP_Exact_ClosedLoop_MinMax(add_usys_d,x_state,Y_x_Limit,U_x_bounds,X_expl_bounds,W_x_bounds,Q,R,N,norm_type)

