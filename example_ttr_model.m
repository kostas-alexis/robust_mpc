%%  Rotorcraft Parameters
%
%   This is just a test-file
%
%   Authors: Kostas Alexis (konstantinos.alexis@mavt.ethz.ch)

%%  Step 1: Define TTR-parameters

dmp_x = 0.1;
gamma_0 = 0;
m_B = 2.5;
g = 9.8065;
F_0 = m_B*g;

A_x = [0  1;
     0  -dmp_x]; 
 
B_x = [0;
     (cos(gamma_0)*F_0)/m_B];

C_x = eye(2);

D_x = 0*B_x;



sys_x = ss(A_x,B_x,C_x,D_x);

%%  Discretize
disp('### Discretize')

sys_x_d = c2d(sys_x,Ts,'zoh');