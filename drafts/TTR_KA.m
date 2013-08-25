%% Subsystem Dynamics

% Rotor Dynamics
hr=tf(7.655946120461085,[0.145992771705270 1]);   hr.OutputDelay=0.03388;
hl=tf(7.531092760896522,[0.141638503909445 1]);   hl.OutputDelay=0.034055;
PolyR_R2T = [0.004088843035973 -8.629151839250008]; PolyL_R2T = [0.003950480213225 -8.757691155123139];  
tf_RL = tf( 0.5*(PolyR_R2T(1)*hr.num{1}+PolyL_R2T(1)*hl.num{1}) , 0.5*(hr.den{1}+hl.den{1}) ); 
tf_RL.num{1} = 1;  %Assume Directly Controlling Force (dcgain=1)
tf_RL.InputDelay = 0.5*(hr.ioDelay+hr.InputDelay+hr.OutputDelay + hl.ioDelay+hl.InputDelay+hl.OutputDelay);
ss_RL = ss(tf_RL); ss_RL.B=ss_RL.B*ss_RL.C; ss_RL.C=1;

% Servo Dynamics
ss_S = ss(-200,200,1,0);  %Assume Directly Controlling Radians (dcgain=1)
ss_S.InputDelay = 0.02;

%Closed-Loop phi Dynamics
%Old
PHI = tf(1.119,[0.0355 0.1663 1]);   PHI.InputDelay=0.04;
%New
%PHI = tf(0.99749,[0.21585 1]);   PHI.InputDelay=0.15517;
%ss
ss_PHI = idss(PHI,'SSParameterization','Canonical');

%% Fixed Parameters

Ts_slow = 0.250;

%Mechanical Setup
m_B = 2.35;
g = 9.81;
d_RL_x = 0.0250;
d_T_x = 0.355;

dmp_x = 0.1;
dmp_y = 0.1;
dmp_z = 0.1;

%%
% X = [x;x_dot;delta_g]

g_0 = 0;
F_0 = ( (m_B*g)/(1+(d_RL_x/d_T_x)) )/cos(g_0);

A = [0  1       0;
     0  -dmp_x  (cos(g_0)*F_0)/m_B;
     0  0       ss_S.A];
     
B = [0;
     0;
     ss_S.B];

C = eye(3);
D = zeros(3,1);

TTR_X=ss(A,B,C,D);
TTR_X.InputDelay(1) = ss_S.InputDelay;
TTR_X_d=c2d(TTR_X,Ts_slow,'zoh');

%%
% Z = [z;z_dot;delta_F]

g_0 = 0;
F_0 = ( (m_B*g)/(1+(d_RL_x/d_T_x)) )/cos(g_0);

A = [0  1       0;
     0  -dmp_z  cos(g_0)/m_B;
     0  0       ss_RL.A];

B = [0;
     0;
     ss_RL.B];

C = eye(3);
D = zeros(3,1);

TTR_Z=ss(A,B,C,D);
TTR_Z.InputDelay(1) = ss_RL.InputDelay;
TTR_Z_d=c2d(TTR_Z,Ts_slow,'zoh');

%%
% Y = [y;y_dot;phi]  OLD

g_0 = 0;
F_0 = ( (m_B*g)/(1+(d_RL_x/d_T_x)) )/cos(g_0);

A = [0  1       0                   0;
     0  -dmp_y  (cos(g_0)*F_0)/m_B  0;
     0  0       ss_PHI.A(1,1)       ss_PHI.A(1,2);
     0  0       ss_PHI.A(2,1)       ss_PHI.A(2,2)];

B = [0;
     0;
     ss_PHI.B(1,1);
     ss_PHI.B(2,1)];

C = eye(4);
D = zeros(4,1);

TTR_Y=ss(A,B,C,D);
TTR_Y.InputDelay(1) = ss_PHI.InputDelay;
TTR_Y_d=c2d(TTR_Y,Ts_slow,'zoh');

%%
% Y = [y;y_dot;phi]  NEW

g_0 = 0;
F_0 = ( (m_B*g)/(1+(d_RL_x/d_T_x)) )/cos(g_0);

A = [0  1       0;
     0  -dmp_y  (cos(g_0)*F_0)/m_B;
     0  0       ss_PHI.A];

B = [0;
     0;
     ss_PHI.B];

C = eye(3);
D = zeros(3,1);

TTR_Y=ss(A,B,C,D);
TTR_Y.InputDelay(1) = ss_PHI.InputDelay;
TTR_Y_d=c2d(TTR_Y,Ts_slow,'zoh');