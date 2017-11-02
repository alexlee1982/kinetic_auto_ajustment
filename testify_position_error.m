% % 建立 以距离误差模型为基础的误差分析模型。
% % 
% % 
% % 符号推导 运动学正解
% % 定义D-H参数变量

dgree=pi/180;

D_th1=0.01*dgree;
D_th2=0.02*dgree;
D_th3=0.03*dgree;
D_th4=0.04*dgree;
D_th5=0.05*dgree;
D_th6=0.06*dgree;

D_bt1=0.01*dgree;
D_bt2=0.03*dgree;
D_bt3=0.05*dgree;
D_bt4=0.07*dgree;
D_bt5=0.09*dgree;
D_bt6=0.06*dgree;

D_d1=0.1;
D_d2=0.2;
D_d3=0.3;
D_d4=0.4;
D_d5=0.5;
D_d6=0.6;


D_a1=0.11;
D_a2=0.21;
D_a3=0.31;
D_a4=0.41;
D_a5=0.51;
D_a6=0;
% 

%  th=[30 20 40 50 50 60];
%  T=F_T16R(th)-F_T16N(th)
% 
% 
deltaQ=[D_th1;D_th2;D_th3;D_th4;D_th5;D_th6;D_bt1;D_bt2;D_bt3;D_bt4;D_bt5;D_bt6;D_a1;D_a2;D_a3;D_a4;D_a5;D_a6;D_d1;D_d2;D_d3;D_d4;D_d5;D_d6];
% deltaQ=[D_th2;D_th3;D_th4;D_th5;D_bt1;D_bt2;D_bt3;D_bt4;D_bt5;D_a1;D_a2;D_a3;D_a4;D_a5;D_a6;D_d2;D_d3;D_d5;D_d6];
% 
E=zeros(27,1);
%th=[-177:14:177];
th=zeros(28,6);
th(1,:)=[-10 -100 -20 -30 -40 -50];
th(2,:)=[10 -80 20 30 40 50];
th(3,:)=[20 -70 30 40 50 60];
th(4,:)=[30 -60 40 50 60 70];
th(5,:)=[40 -50 50 60 70 80];
th(6,:)=[50 -40 60 70 80 90];
th(7,:)=[60 -30 70 80 100 110];
th(8,:)=[70 -25 60 50 40 30];
th(9,:)=[80 -20 70 50 60 80];
th(10,:)=[100 -10 90 80 70 60];
th(11,:)=[30 -40 60 70 80 90];
th(12,:)=[110 -80 90 80 60 70];
th(13,:)=[120 -100 -50 80 30 40];
th(14,:)=[130 -110 -80 -70 -60 -50];
th(15,:)=[140 -120 -100 -80 -70 -60];
th(16,:)=[150 -130 -110 -100 -80 -70];
th(17,:)=[160 -140 -130 -80 -60 -50];
th(18,:)=[-20 100 -30 -30 -30 -30];
th(19,:)=[-30 110 -40 -40 -40 -40];
th(20,:)=[-40 120 -50 -50 -50 -50];
th(21,:)=[-50 130 -60 -60 -60 -60];
th(22,:)=[-60 140 -70 -70 -70 -70];
th(23,:)=[-70 150 -80 -80 -80 -80];
th(24,:)=[-80 160 -100 -100 -100 -100];
th(25,:)=[-100 50 30 40 50 60];
th(26,:)=[-110 60 40 40 40 40];
th(27,:)=[-120 70 50 50 50 50];
th(28,:)=[-130 80 60 60 60 60];




J=zeros(27,24);

for i=1:1:27
    th6=th(i,:)
    T16R_A=F_T16R(th6)
    T16N_A=F_T16N(th6)
    
    Jax=F_J_x(th6)
    Jay=F_J_y(th6)
    Jaz=F_J_z(th6)
    
    Ja=[Jax;Jay;Jaz]
    
    AxN=T16N_A(1,4)
    AyN=T16N_A(2,4)
    AzN=T16N_A(3,4)
    
    AxR=T16R_A(1,4)
    AyR=T16R_A(2,4)
    AzR=T16R_A(3,4)  
    
    th6=th(i+1,:)
    T16R_B=F_T16R(th6)
    T16N_B=F_T16N(th6)
   
    Jbx=F_J_x(th6)
    Jby=F_J_y(th6)
    Jbz=F_J_z(th6)
    
    Jb=[Jbx;Jby;Jbz]
    
    BxN=T16N_B(1,4)
    ByN=T16N_B(2,4)
    BzN=T16N_B(3,4)
    
    BxR=T16R_B(1,4)
    ByR=T16R_B(2,4)
    BzR=T16R_B(3,4)
    
    ABN=sqrt((AxN-BxN)^2+(AyN-ByN)^2+(AzN-BzN)^2)
    ABR=sqrt((AxR-BxR)^2+(AyR-ByR)^2+(AzR-BzR)^2)
    
    E(i)=ABN-ABR
    AB_D_AB=[(BxN-AxN)/ABN (ByN-AyN)/ABN (BzN-AzN)/ABN];
    size(AB_D_AB)
    size(Jb-Ja)
    Ji=AB_D_AB*(Ja-Jb);
    J(i,:)=Ji;
%     E((i-1)*3+1)=T16R(1,4)-T16N(1,4);
%     E((i-1)*3+2)=T16R(2,4)-T16N(2,4);
%     E((i-1)*3+3)=T16R(3,4)-T16N(3,4);
%     J((i-1)*3+1,:)=F_J_x(th6);
%     J((i-1)*3+2,:)=F_J_y(th6);
%     J((i-1)*3+3,:)=F_J_z(th6);
end

delta=J*deltaQ
detltaQ1=J\E
deltaQ
detltaQ1=inv(transpose(J)*J)*transpose(J)*E


% for  i=1:1:24
%    thA=[th(i) th(i) th(i) th(i) th(i) th(i)];
%    thB=[th(i+1) th(i+1) th(i+1) th(i+1) th(i+1) th(i+1)];
%    TAN=F_T16N(thA);
%    TBN=F_T16N(thB);
%    
%    TAR=F_T16R(thA);
%    TBR=F_T16R(thB);
%    
%    xAN=TAN(1,4);
%    yAN=TAN(2,4);
%    zAN=TAN(3,4);
%    
%    xAR=TAR(1,4);
%    yAR=TAR(2,4);
%    zAR=TAR(3,4);
%    
%    xBN=TBN(1,4);
%    yBN=TBN(2,4);
%    zBN=TBN(3,4);
%    
%    xBR=TBR(1,4);
%    yBR=TBR(2,4);
%    zBR=TBR(3,4);
%    
%    LABN=sqrt((xAN-xBN)^2+(yAN-yBN)^2+(zAN-zBN)^2);
%    LABR=sqrt((xAR-xBR)^2+(yAR-yBR)^2+(zAR-zBR)^2);
% 
%    E(i)=LABN-LABR;
% 
%    JxA=F_J_x(thA);
%    JyA=F_J_y(thA);
%    JzA=F_J_z(thA);
%    
%    JxB=F_J_x(thB);
%    JyB=F_J_y(thB);
%    JzB=F_J_z(thB);
%    
%    JA=[JxA;JyA;JzA]
%    JB=[JxB;JyB;JzB]
%    
%    VAB=[(xAN-xBN)/LABN (yAN-yBN)/LABN (zAN-zBN)/LABN]
%    JAB=JA-JB
%    Ji=VAB*JAB
%    J(i,:)=VAB*JAB    
% end
% % detltaQ1=inv(J.'*J)*(J.')*E
% detltaQ1=J\E

% 
% 
% 
