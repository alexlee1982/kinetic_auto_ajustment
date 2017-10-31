function [ A ] = AiR( th,num )
%UNTITLED3 此处显示有关此函数的摘要
%   此处显示详细说明
% 计算关节号码为num的实际矩阵

D_th1=0.01;
D_th2=0.02;
D_th3=0.03;
D_th4=0.04;
D_th5=0.05;
D_th6=0.06;

D_bt1=0.01;
D_bt2=0.03;
D_bt3=0.05;
D_bt4=0.07;
D_bt5=0.09;
D_bt6=0.06;

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
% 实际的误差值，都写在这个函数中间，固定误差。

    bt1=-90;
    bt2=180;
    bt3=-90;
    bt4=90;
    bt5=-90;
    bt6=180;

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
    
    
    bt1=bt1+D_bt1;
    bt2=bt2+D_bt2;
    bt3=bt3+D_bt3;
    bt4=bt4+D_bt4;
    bt5=bt5+D_bt5;
    bt6=bt6+D_bt6;

    d1=d1+D_d1;
    d2=d2+D_d2;
    d3=d3+D_d3;
    d4=d4+D_d4;
    d5=d5+D_d5;
    d6=d6+D_d6;

    a1=a1+D_a1;
    a2=a2+D_a2;
    a3=a3+D_a3;
    a4=a4+D_a4;
    a5=a5+D_a5;
    a6=a6+D_a6;
%名义参数与理论值相同。

    if(num==1)
        th=th+D_th1;
        A=[cosd(th),-sind(th)*cosd(bt1),sind(th)*sind(bt1),a1*cosd(th);
           sind(th),cosd(th)*cosd(bt1),-cosd(th)*sind(bt1),a1*sind(th);
           0,sind(bt1),cosd(bt1),d1 ;
            0,0,0,1];
    elseif(num==2)
        th=th+D_th2;
         A=[cosd(th),-sind(th)*cosd(bt2),sind(th)*sind(bt2),a2*cosd(th);
           sind(th),cosd(th)*cosd(bt2),-cosd(th)*sind(bt2),a2*sind(th);
           0,sind(bt2),cosd(bt2),d2 ;
            0,0,0,1];
    elseif(num==3)
        th=th+D_th3;
          A=[cosd(th),-sind(th)*cosd(bt3),sind(th)*sind(bt3),a3*cosd(th);
           sind(th),cosd(th)*cosd(bt3),-cosd(th)*sind(bt3),a3*sind(th);
           0,sind(bt3),cosd(bt3),d3 ;
            0,0,0,1];           
    elseif(num==4)
        th=th+D_th4;
           A=[cosd(th),-sind(th)*cosd(bt4),sind(th)*sind(bt4),a4*cosd(th);
           sind(th),cosd(th)*cosd(bt4),-cosd(th)*sind(bt4),a4*sind(th);
           0,sind(bt4),cosd(bt4),d4 ;
            0,0,0,1];         
    elseif(num==5)
        th=th+D_th5;
          A=[cosd(th),-sind(th)*cosd(bt5),sind(th)*sind(bt5),a5*cosd(th);
           sind(th),cosd(th)*cosd(bt5),-cosd(th)*sind(bt5),a5*sind(th);
           0,sind(bt5),cosd(bt5),d5 ;
            0,0,0,1];           
    elseif(num==6)
        th=th+D_th6;
           A=[cosd(th),-sind(th)*cosd(bt6),sind(th)*sind(bt6),a6*cosd(th);
           sind(th),cosd(th)*cosd(bt6),-cosd(th)*sind(bt6),a6*sind(th);
           0,sind(bt6),cosd(bt6),d6 ;
            0,0,0,1];          
    end



end

