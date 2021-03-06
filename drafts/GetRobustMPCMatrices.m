function [H,K,F,G,Nc] = GetRobustMPCMatrices(sol_mp)
%%
nr = length(sol_mp.dynamics);


Pn = sol_mp.Pn;
%%
Pn_plh = [];
for kk = 1:length(Pn)
    [HH,KK] = double(Pn.A);
    Pn_plh = [Pn_plh; Polyhedron(HH,KK)];
end
%%
Pn = Pn_plh
%   extract hyperplane representation
Hn = cell(nr,1);
Kn = cell(nr,1);

% [H_A,K_A] = double(Pn.A);
% Pn_A = Polyhedron(H_A,K_A);
% Pn_A.computeVRep();
% Pn_A_plt = polytope(H_A,K_A);
% [H_b,K_b] = double(Pn.b);
% Pn_b = Polyhedron(H_b,K_b);
% Pn_b.computeVRep();
% Pn_b_plt = polytope(H_b,K_b);

[Hn{:}] = deal(Pn.A);
[Kn{:}] = deal(Pn.b);

Hn_plt = cell(nr,1);
Kn_plt = cell(nr,1);
[Hn_plt{:}] = deal(Pn_A_plt);
[Kn_plt{:}] = deal(Pn_b_plt);

if ~iscell(Hn),
    Hn = {Hn};
    Kn = {Kn};
end
%%

%   extract control law
Fi = sol_mp.Fi;
Gi = sol_mp.Gi;

Nc = zeros(nr,1);

for i = 1:nr;
    Nc(i) = size(Hn{i},1);
end

%%

%   count numer of constraints
nctotal = 0;
for ii = 1:nr
    nctotal = nctotal + size(Pn(ii).H,1);
end
%%

nx = length(sol_mp.Fi{1}); % this should give us the number of states

%%
H = zeros(nctotal,nx);
K = zeros(nctotal,1);
F = zeros(nr,nx);
G = zeros(nr,1);
%%
abspos = 1;
for i = 1:nr
    H(abspos:abspos+Nc(i)-1,:) = Hn_plt{i};
    K(abspos:abspos+Nc(i)-1,:) = Kn_plt{i};
    abspos = abspos + Nc(i);
    
    F(i,:) = Fi{i};
    G(i,:) = Gi{i};
end
%%


%%
obj = ctrl
tempnum = size(obj.feedback,2);
clear Pn;
Pn = [];
nr = 0;
nu = 1;
for i = 1:tempnum
    Pn = [Pn;obj.feedback(i).Set];
    nr = nr + obj.feedback(i).Num;
end


% extract hyperplane representation
Hn = cell(nr,1);
Kn = cell(nr,1);
[Hn{:}]=deal(Pn.A);
[Kn{:}]=deal(Pn.b);
if ~iscell(Hn),
    Hn = {Hn};
    Kn = {Kn};
end
end