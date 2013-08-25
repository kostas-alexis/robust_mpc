%Damping
dmp_x = 0.1;

%Ts
sysStruct.Ts = 0.250;

% X = [x;x_dot] , U = delta_gamma
%% 1 : gamma_0 = 0

gamma_0 = 0*gran;
F_0 = ( (m_B*g)/(1+(d_RL_x/d_T_x)) )/cos(gamma_0);

A = [0  1;
     0  -dmp_x];  
B = [0;
     (cos(gamma_0)*F_0)/m_B];
TTR_FF_d_f = Ts_slow * [0 ;
                        ((sin(gamma_0)*F_0)/m_B)];
C = eye(2);
D = zeros(2,1);
TTR_FF_d_g = Ts_slow * zeros(2,1);

TTR_FF=ss(A,B,C,D);
TTR_FF_d=c2d(TTR_FF,sysStruct.Ts,'zoh');