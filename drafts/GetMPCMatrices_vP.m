function [H,K,F1,G1,F2,G2,Nc,Pn] = GetMPCMatrices_vP(obj)

% Main Modification for support of PWA systems
tempnum = size(obj.feedback,2);
clear Pn;
Pn = [];
nr = 0;
nu = obj.model.nu;
for i = 1:tempnum
    Pn = [Pn;obj.feedback(i).Set];
    nr = nr + obj.feedback(i).Num;
end
if nr~=obj.nr;  error('err_nr!ctrl.nr=');  return;  end

% extract hyperplane representation
Hn = cell(nr,1);
Kn = cell(nr,1);
[Hn{:}]=deal(Pn.A);
[Kn{:}]=deal(Pn.b);
if ~iscell(Hn),
    Hn = {Hn};
    Kn = {Kn};
end

% extract control law
Fi = cell(nr,1);
Gi = Fi;
for i=1:nr
    %Frows=size(Pn(i).getFunction('primal').F,1); if find(any(Pn(i).getFunction('primal').F(nu+1:Frows,:))); disp(Pn(i).getFunction('primal').F); disp(i); error('shit1'); return; end;
    %grows=size(Pn(i).getFunction('primal').g,1); if find(any(Pn(i).getFunction('primal').g(nu+1:grows))); disp(Pn(i).getFunction('primal').g); disp(i); error('shit2'); return; end; 
    Fi{i}=Pn(i).getFunction('primal').F(1:nu,:);
    Gi{i}=Pn(i).getFunction('primal').g(1:nu);
end

Nc = zeros(nr,1);
for i = 1:nr
    Nc(i) = size(Hn{i},1);
end

% count number of constraints
nctotal = 0;
for ii=1:nr,
    nctotal = nctotal + size(Pn(ii).H,1);
end

nx = obj.nx;
H = zeros(nctotal,nx);
K = zeros(nctotal,1);
F1 = zeros(nr,nx);
G1 = zeros(nr,1);
F2 = zeros(nr,nx);
G2 = zeros(nr,1);

abspos = 1;
for i = 1:nr
    H(abspos:abspos+Nc(i)-1,:) = Hn{i};
    K(abspos:abspos+Nc(i)-1,:) = Kn{i};
    abspos = abspos + Nc(i);

    Ftmp = Fi{i};
    Gtmp = Gi{i};
    F1(i,:) = Ftmp(1,:);
    G1(i,:) = Gtmp(1,:);
    F2(i,:) = Ftmp(2,:);
    G2(i,:) = Gtmp(2,:);
end

return