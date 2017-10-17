
%定义D-H参数变量
syms th1 th2 th3 th4 th5 th6;
syms bt1 bt2 bt3 bt4 bt5 bt6;
syms d1 d2 d3 d4 d5 d6;
syms a1 a2 a3 a4 a5 a6;

syms L11 L2 L3 L4 L6


% bt1=-1*pi/2;
% bt2=pi;
% bt3=-1*pi/2;
% bt4=pi/2;
% bt5=-1*pi/2;
% bt6=pi;
% 
% d1=0;
% d2=0;
% d3=0;
% d4=-L4;
% d5=0;
% d6=-L6;
% 
% a1=L11;
% a2=L2;
% a3=L3;
% a4=0;
% a5=0;
% a6=0;

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


%定义D-H参数的微分
syms D_th1 D_th2 D_th3 D_th4 D_th5 D_th6;
syms D_bt1 D_bt2 D_bt3 D_bt4 D_bt5 D_bt6;
syms D_d1 D_d2 D_d3 D_d4 D_d5 D_d6;
syms D_a1 D_a2 D_a3 D_a4 D_a5 D_a6;

%定义运动学正解矩阵 名义矩阵
T1=[c1,-s1*cos(bt1),s1*sin(bt1),a1*c1;s1,c1*cos(bt1),-c1*sin(bt1),a1*s1;0,sin(bt1),cos(bt1),d1;0,0,0,1];
T2=[c2,-s2*cos(bt2),s2*sin(bt2),a2*c2;s2,c2*cos(bt2),-c2*sin(bt2),a2*s2;0,sin(bt2),cos(bt2),d2;0,0,0,1];
T3=[c3,-s3*cos(bt3),s3*sin(bt3),a3*c3;s3,c3*cos(bt3),-c3*sin(bt3),a3*s3;0,sin(bt3),cos(bt3),d3;0,0,0,1];
T4=[c4,-s4*cos(bt4),s4*sin(bt4),a4*c4;s4,c4*cos(bt4),-c4*sin(bt4),a4*s4;0,sin(bt4),cos(bt4),d4;0,0,0,1];
T5=[c5,-s5*cos(bt5),s5*sin(bt5),a5*c5;s5,c5*cos(bt5),-c5*sin(bt5),a5*s5;0,sin(bt5),cos(bt5),d5;0,0,0,1];
T6=[c6,-s6*cos(bt6),s6*sin(bt6),a6*c6;s6,c6*cos(bt6),-c6*sin(bt6),a6*s6;0,sin(bt6),cos(bt6),d6;0,0,0,1];

T1N=[c1,0,-s1,L11*c1;s1,0,c1,L11*s1;0,-1,0,0;0,0,0,1];
T2N=[c2,s2,0,L2*c2;s2,-c2,0,L2*s2;0,0,-1,0;0,0,0,1];
T3N=[c3,0,-s3,L3*c3;s3,0,c3,L3*s3;0,-1,0,0;0,0,0,1];
T4N=[c4,0,s4,0;s4,0,-c4,0;0,1,0,-L4;0,0,0,1];
T5N=[c5,0,-s5,0;s5,0,c5,0;0,-1,0,1;0,0,0,1];
T6N=[c6,s6,0,0;s6,-c6,0,0;0,0,-1,-L6;0,0,0,1];




%单个关节的实际矩阵

dT1=diff(T1,'th1')*D_th1+diff(T1,'bt1')*D_bt1+diff(T1,'d1')*D_d1+diff(T1,'a1')*D_a1;
dT2=diff(T2,'th2')*D_th2+diff(T2,'bt2')*D_bt2+diff(T2,'d2')*D_d1+diff(T2,'a2')*D_a2;
dT3=diff(T3,'th3')*D_th3+diff(T3,'bt3')*D_bt3+diff(T3,'d3')*D_d1+diff(T3,'a3')*D_a3;
dT4=diff(T4,'th4')*D_th4+diff(T4,'bt4')*D_bt4+diff(T4,'d4')*D_d1+diff(T4,'a4')*D_a4;
dT5=diff(T5,'th5')*D_th5+diff(T5,'bt5')*D_bt5+diff(T5,'d5')*D_d1+diff(T5,'a5')*D_a5;
dT6=diff(T6,'th6')*D_th6+diff(T6,'bt6')*D_bt6+diff(T6,'d6')*D_d1+diff(T6,'a6')*D_a6;

%名义矩阵的逆矩阵
Inv_T1=inv(T1);
Inv_T2=inv(T2);
Inv_T3=inv(T3);
Inv_T4=inv(T4);
Inv_T5=inv(T5);
Inv_T6=inv(T6);

%求误差矩阵
Delta_1=Inv_T1*dT1;
Delta_2=Inv_T2*dT2;
Delta_3=Inv_T3*dT3;
Delta_4=Inv_T4*dT4;
Delta_5=Inv_T5*dT5;
Delta_6=Inv_T6*dT6;

Delta_1_2=T1\dT1;
Delta_2_2=T2\dT2;
Delta_3_2=T3\dT3;
Delta_4_2=T4\dT4;
Delta_5_2=T5\dT5;
Delta_6_2=T6\dT6;

%提取出误差向量

e1=simplify([Delta_1_2(1,4),Delta_1_2(2,4),Delta_1_2(3,4),Delta_1_2(3,2),Delta_1_2(1,3),Delta_1_2(2,1)]);
e2=simplify([Delta_2_2(1,4),Delta_2_2(2,4),Delta_2_2(3,4),Delta_2_2(3,2),Delta_2_2(1,3),Delta_2_2(2,1)]);
e3=simplify([Delta_3_2(1,4),Delta_3_2(2,4),Delta_3_2(3,4),Delta_3_2(3,2),Delta_3_2(1,3),Delta_3_2(2,1)]);
e4=simplify([Delta_4_2(1,4),Delta_4_2(2,4),Delta_4_2(3,4),Delta_4_2(3,2),Delta_4_2(1,3),Delta_4_2(2,1)]);
e5=simplify([Delta_5_2(1,4),Delta_5_2(2,4),Delta_5_2(3,4),Delta_5_2(3,2),Delta_5_2(1,3),Delta_5_2(2,1)]);
e6=simplify([Delta_6_2(1,4),Delta_6_2(2,4),Delta_6_2(3,4),Delta_6_2(3,2),Delta_6_2(1,3),Delta_6_2(2,1)]);

%求出误差系数矩阵

% d1=0;
% d2=0;
% d3=0;
% d4=-L4;
% d5=0;
% d6=-L6;
% 
 a1=L11;
 a2=L2;
 a3=L3;
 a4=0;
 a5=0;
 a6=0;


G1=[1,0,0,0;0,-1,0,0;0,0,0,a1;0,0,1,0;0,0,0,-1;0,0,0,0]
G2=[1,0,0,0;0,0,0,-a2;0,-1,0,0;0,0,1,0;0,0,0,0;0,0,0,-1];
G3=[1,0,0,0;0,-1,0,0;0,0,0,a3;0,0,1,0;0,0,0,-1;0,0,0,0];
G4=[1,0,0,0;0,1,0,0;0,0,0,-a4;0,0,1,0;0,0,0,1;0,0,0,0];
G5=[1,0,0,0;0,-1,0,0;0,0,0,a5;0,0,1,0;0,0,0,-1;0,0,0,0];
G6=[1,0,0,0;0,0,0,-a6;0,-1,0,0;0,0,1,0;0,0,0,0;0,0,0,-1];

%求各关节的雅克比矩阵
T16=T2N*T3N*T4N*T5N*T6N;
T26=T3N*T4N*T5N*T6N;
T36=T4N*T5N*T6N;
T46=T5N*T6N;
T56=T6N;


%J16
nx1=T16(1,1);
ny1=T16(2,1);
nz1=T16(3,1);

nx1=simplify(nx1);
ny1=simplify(ny1);
nz1=simplify(nz1);

ox1=simplify(T16(1,2));
oy1=simplify(T16(2,2));
oz1=simplify(T16(3,2));

ax1=simplify(T16(1,3));
ay1=simplify(T16(2,3));
az1=simplify(T16(3,3));

px1=simplify(T16(1,4));
py1=simplify(T16(2,4));
pz1=simplify(T16(3,4));

n1=[nx1;ny1;nz1];
o1=[ox1;oy1;oz1];
a1=[ax1;ay1;az1];
p1=[px1;py1;pz1];

sp1=[0,-1*p1(3,1),p1(2,1);p1(3,1),0,-1*p1(1,1);-1*p1(2,1),p1(1,1),0];
syms pn1 po1 pa1
pn1=sp1*n1;
po1=sp1*o1;
pa1=sp1*a1;

pn1=simplify(pn1);
po1=simplify(po1);
pa1=simplify(pa1);

J16=[nx1,ny1,nz1,pn1(1,1),pn1(2,1),pn1(3,1);ox1,oy1,oz1,po1(1,1),po1(2,1),po1(3,1);ax1,ay1,az1,pa1(1,1),pa1(2,1),pa1(3,1);0,0,0,nx1,ny1,nz1;0,0,0,ox1,oy1,oz1;0,0,0,ax1,ay1,az1];

%J26
nx2=T26(1,1);
ny2=T26(2,1);
nz2=T26(3,1);

nx2=simplify(nx2);
ny2=simplify(ny2);
nz2=simplify(nz2);

ox2=simplify(T26(1,2));
oy2=simplify(T26(2,2));
oz2=simplify(T26(3,2));

ax2=simplify(T26(1,3));
ay2=simplify(T26(2,3));
az2=simplify(T26(3,3));

px2=simplify(T26(1,4));
py2=simplify(T26(2,4));
pz2=simplify(T26(3,4));

n2=[nx2;ny2;nz2];
o2=[ox2;oy2;oz2];
a2=[ax2;ay2;az2];
p2=[px2;py2;pz2];

sp2=[0,-1*p2(3,1),p2(2,1);p2(3,1),0,-1*p2(1,1);-1*p2(2,1),p2(1,1),0];
syms pn2 po2 pa2
pn2=sp2*n2;
po2=sp2*o2;
pa2=sp2*a2;

pn2=simplify(pn2);
po2=simplify(po2);
pa2=simplify(pa2);

J26=[nx2,ny2,nz2,pn2(1,1),pn2(2,1),pn2(3,1);ox2,oy2,oz2,po2(1,1),po2(2,1),po2(3,1);ax2,ay2,az2,pa2(1,1),pa2(2,1),pa2(3,1);0,0,0,nx2,ny2,nz2;0,0,0,ox2,oy2,oz2;0,0,0,ax2,ay2,az2];

%J36

nx3=T36(1,1);
ny3=T36(2,1);
nz3=T36(3,1);

nx3=simplify(nx3);
ny3=simplify(ny3);
nz3=simplify(nz3);

ox3=simplify(T36(1,2));
oy3=simplify(T36(2,2));
oz3=simplify(T36(3,2));

ax3=simplify(T36(1,3));
ay3=simplify(T36(2,3));
az3=simplify(T36(3,3));

px3=simplify(T36(1,4));
py3=simplify(T36(2,4));
pz3=simplify(T36(3,4));

n3=[nx3;ny3;nz3];
o3=[ox3;oy3;oz3];
a3=[ax3;ay3;az3];
p3=[px3;py3;pz3];

sp3=[0,-1*p3(3,1),p3(2,1);p3(3,1),0,-1*p3(1,1);-1*p3(2,1),p3(1,1),0];
syms pn3 po3 pa3
pn3=sp3*n3;
po3=sp3*o3;
pa3=sp3*a3;

pn3=simplify(pn3);
po3=simplify(po3);
pa3=simplify(pa3);

J36=[nx3,ny3,nz3,pn3(1,1),pn3(2,1),pn3(3,1);ox3,oy3,oz3,po3(1,1),po3(2,1),po3(3,1);ax3,ay3,az3,pa3(1,1),pa3(2,1),pa3(3,1);0,0,0,nx3,ny3,nz3;0,0,0,ox3,oy3,oz3;0,0,0,ax3,ay3,az3];

%J4

nx4=T46(1,1);
ny4=T46(2,1);
nz4=T46(3,1);

nx4=simplify(nx4);
ny4=simplify(ny4);
nz4=simplify(nz4);

ox4=simplify(T46(1,2));
oy4=simplify(T46(2,2));
oz4=simplify(T46(3,2));

ax4=simplify(T46(1,3));
ay4=simplify(T46(2,3));
az4=simplify(T46(3,3));

px4=simplify(T46(1,4));
py4=simplify(T46(2,4));
pz4=simplify(T46(3,4));

n4=[nx4;ny4;nz4];
o4=[ox4;oy4;oz4];
a4=[ax4;ay4;az4];
p4=[px4;py4;pz4];

sp4=[0,-1*p4(3,1),p4(2,1);p4(3,1),0,-1*p4(1,1);-1*p4(2,1),p4(1,1),0];
syms pn4 po4 pa4
pn4=sp4*n4;
po4=sp4*o4;
pa4=sp4*a4;

pn4=simplify(pn4);
po4=simplify(po4);
pa4=simplify(pa4);

J46=[nx4,ny4,nz4,pn4(1,1),pn4(2,1),pn4(3,1);ox4,oy4,oz4,po4(1,1),po4(2,1),po4(3,1);ax4,ay4,az4,pa4(1,1),pa4(2,1),pa4(3,1);0,0,0,nx4,ny4,nz4;0,0,0,ox4,oy4,oz4;0,0,0,ax4,ay4,az4];
%J56

nx5=T56(1,1);
ny5=T56(2,1);
nz5=T56(3,1);

nx5=simplify(nx5);
ny5=simplify(ny5);
nz5=simplify(nz5);

ox5=simplify(T56(1,2));
oy5=simplify(T56(2,2));
oz5=simplify(T56(3,2));

ax5=simplify(T56(1,3));
ay5=simplify(T56(2,3));
az5=simplify(T56(3,3));

px5=simplify(T56(1,4));
py5=simplify(T56(2,4));
pz5=simplify(T56(3,4));

n5=[nx5;ny5;nz5];
o5=[ox5;oy5;oz5];
a5=[ax5;ay5;az5];
p5=[px5;py5;pz5];

sp5=[0,-1*p5(3,1),p5(2,1);p5(3,1),0,-1*p5(1,1);-1*p5(2,1),p5(1,1),0];
syms pn5 po5 pa5
pn5=sp5*n5;
po5=sp5*o5;
pa5=sp5*a5;

pn5=simplify(pn5);
po5=simplify(po5);
pa5=simplify(pa5);

J56=[nx5,ny5,nz5,pn5(1,1),pn5(2,1),pn5(3,1);ox5,oy5,oz5,po5(1,1),po5(2,1),po5(3,1);ax5,ay5,az5,pa5(1,1),pa5(2,1),pa5(3,1);0,0,0,nx5,ny5,nz5;0,0,0,ox5,oy5,oz5;0,0,0,ax5,ay5,az5];
%J66
T66=eye(4,4);
nx6=T66(1,1);
ny6=T66(2,1);
nz6=T66(3,1);



ox6=T66(1,2);
oy6=T66(2,2);
oz6=T66(3,2);

ax6=T66(1,3);
ay6=T66(2,3);
az6=T66(3,3);

px6=T66(1,4);
py6=T66(2,4);
pz6=T66(3,4);

n6=[nx6;ny6;nz6];
o6=[ox6;oy6;oz6];
a6=[ax6;ay6;az6];
p6=[px6;py6;pz6];

sp6=[0,-1*p6(3,1),p6(2,1);p6(3,1),0,-1*p6(1,1);-1*p6(2,1),p6(1,1),0];
syms pn6 po6 pa6
pn6=sp6*n6;
po6=sp6*o6;
pa6=sp6*a6;

J66=[nx6,ny6,nz6,pn6(1,1),pn6(2,1),pn6(3,1);ox6,oy6,oz6,po6(1,1),po6(2,1),po6(3,1);ax6,ay6,az6,pa6(1,1),pa6(2,1),pa6(3,1);0,0,0,nx6,ny6,nz6;0,0,0,ox6,oy6,oz6;0,0,0,ax6,ay6,az6];

%求误差集合，Ji*ei与 Ji*Gi*deltaXi

deltaX1=[D_a1,D_d1,D_bt1,D_th1];
deltaX2=[D_a2,D_d2,D_bt2,D_th2];
deltaX3=[D_a3,D_d3,D_bt3,D_th3];
deltaX4=[D_a4,D_d4,D_bt4,D_th4];
deltaX5=[D_a5,D_d5,D_bt5,D_th5];
deltaX6=[D_a6,D_d6,D_bt6,D_th6];



E_1=J16*e1.'+J26*e2.'+J36*e3.'+J46*e4.'+J56*e5.'+J66*e6.';
E=J16*G1*deltaX1.'+J26*G2*deltaX2.'+J36*G3*deltaX3.'+J46*G4*deltaX4.'+J56*G5*deltaX5.'+J66*G6*deltaX6.';

%将 E和E_1新型化简
%E=simplify(E)
%E_1=simplify(E_1)




E=subs(E,sin(th1),'s1');
E=subs(E,sin(th2),'s2');
E=subs(E,sin(th3),'s3');
E=subs(E,sin(th4),'s4');
E=subs(E,sin(th5),'s5');
E=subs(E,sin(th6),'s6');

E=subs(E,cos(th1),'c1');
E=subs(E,cos(th2),'c2');
E=subs(E,cos(th3),'c3');
E=subs(E,cos(th4),'c4');
E=subs(E,cos(th5),'c5');
E=subs(E,cos(th6),'c6');



% d1=0;
% d2=0;
% d3=0;
% d4=-L4;
% d5=0;
% d6=-L6;
% 
% a1=L11;
% a2=L2;
% a3=L3;
% a4=0;
% a5=0;
% a6=0;

E_D_th1=diff(E,'D_th1')
E_D_th2=diff(E,'D_th2')
E_D_th3=diff(E,'D_th3')
E_D_th4=diff(E,'D_th4')
E_D_th5=diff(E,'D_th5')
E_D_th6=diff(E,'D_th6')

E_D_bt1=diff(E,'D_bt1')
E_D_bt2=diff(E,'D_bt2')
E_D_bt3=diff(E,'D_bt3')
E_D_bt4=diff(E,'D_bt4')
E_D_bt5=diff(E,'D_bt5')
E_D_bt6=diff(E,'D_bt6')

E_D_a1=diff(E,'D_a1')
E_D_a2=diff(E,'D_a2')
E_D_a3=diff(E,'D_a3')
E_D_a4=diff(E,'D_a4')
E_D_a5=diff(E,'D_a5')
E_D_a6=diff(E,'D_a6')

E_D_d1=diff(E,'D_d1')
E_D_d2=diff(E,'D_d2')
E_D_d3=diff(E,'D_d3')
E_D_d4=diff(E,'D_d4')
E_D_d5=diff(E,'D_d5')
E_D_d6=diff(E,'D_ad')



