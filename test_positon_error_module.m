%建立 以距离误差模型为基础的误差分析模型。


%符号推导 运动学正解
%定义D-H参数变量


syms th1 th2 th3 th4 th5 th6;
syms bt1 bt2 bt3 bt4 bt5 bt6;
syms d1 d2 d3 d4 d5 d6;
syms a1 a2 a3 a4 a5 a6;

syms L11 L2 L3 L4 L6

%定义D-H参数的微分
syms D_th1 D_th2 D_th3 D_th4 D_th5 D_th6;
syms D_bt1 D_bt2 D_bt3 D_bt4 D_bt5 D_bt6;
syms D_d1 D_d2 D_d3 D_d4 D_d5 D_d6;
syms D_a1 D_a2 D_a3 D_a4 D_a5 D_a6;

syms s1 s2 s3 s4 s5 s6 c1 c2 c3 c4 c5 c6
s1=sin(th1);
s2=sin(th2);
s3=sin(th3);
s4=sin(th4);
s5=sin(th5);
s6=sin(th6);

c1=cos(th1);
c2=cos(th2);
c3=cos(th3);
c4=cos(th4);
c5=cos(th5);
c6=cos(th6);


T1=[c1,-s1*cos(bt1),s1*sin(bt1),a1*c1;s1,c1*cos(bt1),-c1*sin(bt1),a1*s1;0,sin(bt1),cos(bt1),d1;0,0,0,1];
T2=[c2,-s2*cos(bt2),s2*sin(bt2),a2*c2;s2,c2*cos(bt2),-c2*sin(bt2),a2*s2;0,sin(bt2),cos(bt2),d2;0,0,0,1];
T3=[c3,-s3*cos(bt3),s3*sin(bt3),a3*c3;s3,c3*cos(bt3),-c3*sin(bt3),a3*s3;0,sin(bt3),cos(bt3),d3;0,0,0,1];
T4=[c4,-s4*cos(bt4),s4*sin(bt4),a4*c4;s4,c4*cos(bt4),-c4*sin(bt4),a4*s4;0,sin(bt4),cos(bt4),d4;0,0,0,1];
T5=[c5,-s5*cos(bt5),s5*sin(bt5),a5*c5;s5,c5*cos(bt5),-c5*sin(bt5),a5*s5;0,sin(bt5),cos(bt5),d5;0,0,0,1];
T6=[c6,-s6*cos(bt6),s6*sin(bt6),a6*c6;s6,c6*cos(bt6),-c6*sin(bt6),a6*s6;0,sin(bt6),cos(bt6),d6;0,0,0,1];


T16=T1*T2*T3*T4*T5*T6;


px=T16(1,4);
py=T16(2,4);
pz=T16(3,4);

dpxth1=diff(px,'th1');
dpxth2=diff(px,'th2');
dpxth3=diff(px,'th3');
dpxth4=diff(px,'th4');
dpxth5=diff(px,'th5');
dpxth6=diff(px,'th6');

dpxbt1=diff(px,'bt1');
dpxbt2=diff(px,'bt2');
dpxbt3=diff(px,'bt3');
dpxbt4=diff(px,'bt4');
dpxbt5=diff(px,'bt5');
dpxbt6=diff(px,'bt6');

dpxa1=diff(px,'a1');
dpxa2=diff(px,'a2');
dpxa3=diff(px,'a3');
dpxa4=diff(px,'a4');
dpxa5=diff(px,'a5');
dpxa6=diff(px,'a6');

dpxd1=diff(px,'d1');
dpxd2=diff(px,'d2');
dpxd3=diff(px,'d3');
dpxd4=diff(px,'d4');
dpxd5=diff(px,'d5');
dpxd6=diff(px,'d6');

% 对py求偏导数

dpyth1=diff(py,'th1');
dpyth2=diff(py,'th2');
dpyth3=diff(py,'th3');
dpyth4=diff(py,'th4');
dpyth5=diff(py,'th5');
dpyth6=diff(py,'th6');

dpybt1=diff(py,'bt1');
dpybt2=diff(py,'bt2');
dpybt3=diff(py,'bt3');
dpybt4=diff(py,'bt4');
dpybt5=diff(py,'bt5');
dpybt6=diff(py,'bt6');

dpya1=diff(py,'a1');
dpya2=diff(py,'a2');
dpya3=diff(py,'a3');
dpya4=diff(py,'a4');
dpya5=diff(py,'a5');
dpya6=diff(py,'a6');

dpyd1=diff(py,'d1');
dpyd2=diff(py,'d2');
dpyd3=diff(py,'d3');
dpyd4=diff(py,'d4');
dpyd5=diff(py,'d5');
dpyd6=diff(py,'d6');


% 对pz求偏导数

dpzth1=diff(pz,'th1');
dpzth2=diff(pz,'th2');
dpzth3=diff(pz,'th3');
dpzth4=diff(pz,'th4');
dpzth5=diff(pz,'th5');
dpzth6=diff(pz,'th6');

dpzbt1=diff(pz,'bt1');
dpzbt2=diff(pz,'bt2');
dpzbt3=diff(pz,'bt3');
dpzbt4=diff(pz,'bt4');
dpzbt5=diff(pz,'bt5');
dpzbt6=diff(pz,'bt6');

dpza1=diff(pz,'a1');
dpza2=diff(pz,'a2');
dpza3=diff(pz,'a3');
dpza4=diff(pz,'a4');
dpza5=diff(pz,'a5');
dpza6=diff(pz,'a6');

dpzd1=diff(pz,'d1');
dpzd2=diff(pz,'d2');
dpzd3=diff(pz,'d3');
dpzd4=diff(pz,'d4');
dpzd5=diff(pz,'d5');
dpzd6=diff(pz,'d6');



% deltaPx=diff(px,'th1')*D_th1+diff(px,'th2')*D_th2+diff(px,'th3')*D_th3+diff(px,'th4')*D_th4+diff(px,'th5')*D_th5+diff(px,'th6')*D_th6;
% deltaPx=deltaPx+diff(px,'bt1')*D_bt1+diff(px,'bt2')*D_bt2+diff(px,'bt3')*D_bt3+diff(px,'bt4')*D_bt4+diff(px,'bt5')*D_bt5+diff(px,'bt6')*D_bt6;
% deltaPx=deltaPx+diff(px,'a1')*D_a1+diff(px,'a2')*D_a2+diff(px,'a3')*D_a3+diff(px,'a4')*D_a4+diff(px,'a5')*D_a5+diff(px,'a6')*D_a6;
% deltaPx=deltaPx+diff(px,'d1')*D_d1+diff(px,'d2')*D_d2+diff(px,'d3')*D_d3+diff(px,'d4')*D_d4+diff(px,'d5')*D_d5+diff(px,'d6')*D_d6;
% 
% deltaPy=diff(py,'th1')*D_th1+diff(py,'th2')*D_th2+diff(py,'th3')*D_th3+diff(py,'th4')*D_th4+diff(py,'th5')*D_th5+diff(py,'th6')*D_th6;
% deltaPy=deltaPy+diff(py,'bt1')*D_bt1+diff(py,'bt2')*D_bt2+diff(py,'bt3')*D_bt3+diff(py,'bt4')*D_bt4+diff(py,'bt5')*D_bt5+diff(py,'bt6')*D_bt6;
% deltaPy=deltaPy+diff(py,'a1')*D_a1+diff(py,'a2')*D_a2+diff(py,'a3')*D_a3+diff(py,'a4')*D_a4+diff(py,'a5')*D_a5+diff(py,'a6')*D_a6;
% deltaPy=deltaPy+diff(py,'d1')*D_d1+diff(py,'d2')*D_d2+diff(py,'d3')*D_d3+diff(py,'d4')*D_d4+diff(py,'d5')*D_d5+diff(py,'d6')*D_d6;
% 
% 
% deltaPz=diff(pz,'th1')*D_th1+diff(pz,'th2')*D_th2+diff(pz,'th3')*D_th3+diff(pz,'th4')*D_th4+diff(pz,'th5')*D_th5+diff(pz,'th6')*D_th6;
% deltaPz=deltaPz+diff(pz,'bt1')*D_bt1+diff(pz,'bt2')*D_bt2+diff(pz,'bt3')*D_bt3+diff(pz,'bt4')*D_bt4+diff(pz,'bt5')*D_bt5+diff(pz,'bt6')*D_bt6;
% deltaPz=deltaPz+diff(pz,'a1')*D_a1+diff(pz,'a2')*D_a2+diff(pz,'a3')*D_a3+diff(pz,'a4')*D_a4+diff(pz,'a5')*D_a5+diff(pz,'a6')*D_a6;
% deltaPz=deltaPz+diff(pz,'d1')*D_d1+diff(pz,'d2')*D_d2+diff(pz,'d3')*D_d3+diff(pz,'d4')*D_d4+diff(pz,'d5')*D_d5+diff(pz,'d6')*D_d6;
syms pi

dgree=pi/180;

% th1=10*dgree;
% th2=20*dgree;
% th3=30*dgree;
% th4=40*dgree;
% th5=50*dgree;
% th6=60*dgree;
% 
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
bt1=-90*dgree;
bt2=180*dgree;
bt3=-90*dgree;
bt4=90*dgree;
bt5=-90*dgree;
bt6=180*dgree;



d1=0;
d2=0;
d3=0;
d4=-300;
d5=0;
d6=-100;

a1=100;
a2=300;
a3=20;
a4=0;
a5=0;
a6=0;

% pi=3.14;

% deltaPx=eval(deltaPx);
% deltaPy=eval(deltaPy);
% deltaPz=eval(deltaPz);

% th=[10 20 30 40 50 60];
%T=F_T16R(th)-F_T16N(th);
% here we already testifid the correctness of zhe Jacobin 
% and then we will do the real deal, we are going to do the distance error
% auto calibration

% ok ,we know that our Jacobin is correct , then , how could we write a
% function for that so we can make our life easier

% dpxth1=eval(dpxth1)*D_th1;
% dpxth2=eval(dpxth2)*D_th2;
% dpxth3=eval(dpxth3)*D_th3;
% dpxth4=eval(dpxth4)*D_th4;
% dpxth5=eval(dpxth5)*D_th5;
% dpxth6=eval(dpxth6)*D_th6;
% 
% dpxbt1=eval(dpxbt1)*D_bt1;
% dpxbt2=eval(dpxbt2)*D_bt2;
% dpxbt3=eval(dpxbt3)*D_bt3;
% dpxbt4=eval(dpxbt4)*D_bt4;
% dpxbt5=eval(dpxbt5)*D_bt5;
% dpxbt6=eval(dpxbt6)*D_bt6;
% 
% dpxa1=eval(dpxa1)*D_a1;
% dpxa2=eval(dpxa2)*D_a2;
% dpxa3=eval(dpxa3)*D_a3;
% dpxa4=eval(dpxa4)*D_a4;
% dpxa5=eval(dpxa5)*D_a5;
% dpxa6=eval(dpxa6)*D_a6;
% 
% dpxd1=eval(dpxd1)*D_d1;
% dpxd2=eval(dpxd2)*D_d2;
% dpxd3=eval(dpxd3)*D_d3;
% dpxd4=eval(dpxd4)*D_d4;
% dpxd5=eval(dpxd5)*D_d5;
% dpxd6=eval(dpxd6)*D_d6;
% 
% %打印出py偏导数的各项系数
% 
% % 
% dpyth1=eval(dpyth1)*D_th1;
% dpyth2=eval(dpyth2)*D_th2;
% dpyth3=eval(dpyth3)*D_th3;
% dpyth4=eval(dpyth4)*D_th4;
% dpyth5=eval(dpyth5)*D_th5;
% dpyth6=eval(dpyth6)*D_th6;
% 
% dpybt1=eval(dpybt1)*D_bt1;
% dpybt2=eval(dpybt2)*D_bt2;
% dpybt3=eval(dpybt3)*D_bt3;
% dpybt4=eval(dpybt4)*D_bt4;
% dpybt5=eval(dpybt5)*D_bt5;
% dpybt6=eval(dpybt6)*D_bt6;
% 
% dpya1=eval(dpya1)*D_a1;
% dpya2=eval(dpya2)*D_a2;
% dpya3=eval(dpya3)*D_a3;
% dpya4=eval(dpya4)*D_a4;
% dpya5=eval(dpya5)*D_a5;
% dpya6=eval(dpya6)*D_a6;
% 
% dpyd1=eval(dpyd1)*D_d1;
% dpyd2=eval(dpyd2)*D_d2;
% dpyd3=eval(dpyd3)*D_d3;
% dpyd4=eval(dpyd4)*D_d4;
% dpyd5=eval(dpyd5)*D_d5;
% dpyd6=eval(dpyd6)*D_d6;
% 
% %打印出pz偏导数的各项系数
% 
% dpzth1=eval(dpzth1)*D_th1;
% dpzth2=eval(dpzth2)*D_th2;
% dpzth3=eval(dpzth3)*D_th3;
% dpzth4=eval(dpzth4)*D_th4;
% dpzth5=eval(dpzth5)*D_th5;
% dpzth6=eval(dpzth6)*D_th6;
% 
% dpzbt1=eval(dpzbt1)*D_bt1;
% dpzbt2=eval(dpzbt2)*D_bt2;
% dpzbt3=eval(dpzbt3)*D_bt3;
% dpzbt4=eval(dpzbt4)*D_bt4;
% dpzbt5=eval(dpzbt5)*D_bt5;
% dpzbt6=eval(dpzbt6)*D_bt6;
% 
% dpza1=eval(dpza1)*D_a1;
% dpza2=eval(dpza2)*D_a2;
% dpza3=eval(dpza3)*D_a3;
% dpza4=eval(dpza4)*D_a4;
% dpza5=eval(dpza5)*D_a5;
% dpza6=eval(dpza6)*D_a6;
% 
% dpzd1=eval(dpzd1)*D_d1;
% dpzd2=eval(dpzd2)*D_d2;
% dpzd3=eval(dpzd3)*D_d3;
% dpzd4=eval(dpzd4)*D_d4;
% dpzd5=eval(dpzd5)*D_d5;
% dpzd6=eval(dpzd6)*D_d6;

%验证 F_J是否正确

% th=[10 20 30 40 50 60];
% T=F_T16R(th)-F_T16N(th)
% 
% Ex=dpxth1+dpxth2+dpxth3+dpxth4+dpxth5+dpxth6+dpxbt1+dpxbt2+dpxbt3+dpxbt4+dpxbt5+dpxbt6+dpxa1+dpxa2+dpxa3+dpxa4+dpxa5+dpxa6+dpxd1+dpxd2+dpxd3+dpxd4+dpxd5+dpxd6
% Ey=dpyth1+dpyth2+dpyth3+dpyth4+dpyth5+dpyth6+dpybt1+dpybt2+dpybt3+dpybt4+dpybt5+dpybt6+dpya1+dpya2+dpya3+dpya4+dpya5+dpya6+dpyd1+dpyd2+dpyd3+dpyd4+dpyd5+dpyd6
% Ez=dpzth1+dpzth2+dpzth3+dpzth4+dpzth5+dpzth6+dpzbt1+dpzbt2+dpzbt3+dpzbt4+dpzbt5+dpzbt6+dpza1+dpza2+dpza3+dpza4+dpza5+dpza6+dpzd1+dpzd2+dpzd3+dpzd4+dpzd5+dpzd6
% 
% 
% deltaQ=[D_th1;D_bt1;D_a1;D_d1;
%         D_th2;D_bt2;D_a2;D_d2;
%         D_th3;D_bt3;D_a3;D_d3;
%         D_th4;D_bt4;D_a4;D_d4;
%         D_th5;D_bt5;D_a5;D_d5;
%         D_th6;D_bt6;D_a6;D_d6
%     ];
% %deltaQ=eval(deltaQ);
% 
% E=F_J(th)*deltaQ




% dpxth1=eval(dpxth1)
% dpxth2=eval(dpxth2)
% dpxth3=eval(dpxth3)
% dpxth4=eval(dpxth4)
% dpxth5=eval(dpxth5)
% dpxth6=eval(dpxth6)
% 
% dpxbt1=eval(dpxbt1)
% dpxbt2=eval(dpxbt2)
% dpxbt3=eval(dpxbt3)
% dpxbt4=eval(dpxbt4)
% dpxbt5=eval(dpxbt5)
% dpxbt6=eval(dpxbt6)
% 
% dpxa1=eval(dpxa1)
% dpxa2=eval(dpxa2)
% dpxa3=eval(dpxa3)
% dpxa4=eval(dpxa4)
% dpxa5=eval(dpxa5)
% dpxa6=eval(dpxa6)
% 
% dpxd1=eval(dpxd1)
% dpxd2=eval(dpxd2)
% dpxd3=eval(dpxd3)
% dpxd4=eval(dpxd4)
% dpxd5=eval(dpxd5)
% dpxd6=eval(dpxd6)
% 
% 
% %打印出py偏导数的各项系数
% 
% % 
% dpyth1=eval(dpyth1)
% dpyth2=eval(dpyth2)
% dpyth3=eval(dpyth3)
% dpyth4=eval(dpyth4)
% dpyth5=eval(dpyth5)
% dpyth6=eval(dpyth6)
% 
% dpybt1=eval(dpybt1)
% dpybt2=eval(dpybt2)
% dpybt3=eval(dpybt3)
% dpybt4=eval(dpybt4)
% dpybt5=eval(dpybt5)
% dpybt6=eval(dpybt6)
% 
% dpya1=eval(dpya1)
% dpya2=eval(dpya2)
% dpya3=eval(dpya3)
% dpya4=eval(dpya4)
% dpya5=eval(dpya5)
% dpya6=eval(dpya6)
% 
% dpyd1=eval(dpyd1)
% dpyd2=eval(dpyd2)
% dpyd3=eval(dpyd3)
% dpyd4=eval(dpyd4)
% dpyd5=eval(dpyd5)
% dpyd6=eval(dpyd6)

% %打印出pz偏导数的各项系数
% 
dpzth1=eval(dpzth1)
dpzth2=eval(dpzth2)
dpzth3=eval(dpzth3)
dpzth4=eval(dpzth4)
dpzth5=eval(dpzth5)
dpzth6=eval(dpzth6)

dpzbt1=eval(dpzbt1)
dpzbt2=eval(dpzbt2)
dpzbt3=eval(dpzbt3)
dpzbt4=eval(dpzbt4)
dpzbt5=eval(dpzbt5)
dpzbt6=eval(dpzbt6)

dpza1=eval(dpza1)
dpza2=eval(dpza2)
dpza3=eval(dpza3)
dpza4=eval(dpza4)
dpza5=eval(dpza5)
dpza6=eval(dpza6)

dpzd1=eval(dpzd1)
dpzd2=eval(dpzd2)
dpzd3=eval(dpzd3)
dpzd4=eval(dpzd4)
dpzd5=eval(dpzd5)
dpzd6=eval(dpzd6)






