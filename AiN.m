function [ A ] = AiN( th,num )
%UNTITLED2 此处显示有关此函数的摘要
%   此处显示详细说明 计算第num个关节变换矩阵的名义矩阵，th代表输入的关节角度。
%定义一些常量
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
    
    if(num==1)
        A=[cosd(th),-sind(th)*cosd(bt1),sind(th)*sind(bt1),a1*cosd(th);
           sind(th),cosd(th)*cosd(bt1),-cosd(th)*sind(bt1),a1*sind(th);
           0,sind(bt1),cosd(bt1),d1 ;
            0,0,0,1];
    elseif(num==2)
         A=[cosd(th),-sind(th)*cosd(bt2),sind(th)*sind(bt2),a2*cosd(th);
           sind(th),cosd(th)*cosd(bt2),-cosd(th)*sind(bt2),a2*sind(th);
           0,sind(bt2),cosd(bt2),d2 ;
            0,0,0,1];
    elseif(num==3)
          A=[cosd(th),-sind(th)*cosd(bt3),sind(th)*sind(bt3),a3*cosd(th);
           sind(th),cosd(th)*cosd(bt3),-cosd(th)*sind(bt3),a3*sind(th);
           0,sind(bt3),cosd(bt3),d3 ;
            0,0,0,1];           
    elseif(num==4)
           A=[cosd(th),-sind(th)*cosd(bt4),sind(th)*sind(bt4),a4*cosd(th);
           sind(th),cosd(th)*cosd(bt4),-cosd(th)*sind(bt4),a4*sind(th);
           0,sind(bt4),cosd(bt4),d4 ;
            0,0,0,1];         
    elseif(num==5)
          A=[cosd(th),-sind(th)*cosd(bt5),sind(th)*sind(bt5),a5*cosd(th);
           sind(th),cosd(th)*cosd(bt5),-cosd(th)*sind(bt5),a5*sind(th);
           0,sind(bt5),cosd(bt5),d5 ;
            0,0,0,1];           
    elseif(num==6)
           A=[cosd(th),-sind(th)*cosd(bt6),sind(th)*sind(bt6),a6*cosd(th);
           sind(th),cosd(th)*cosd(bt6),-cosd(th)*sind(bt6),a6*sind(th);
           0,sind(bt6),cosd(bt6),d6 ;
            0,0,0,1];          
    end
end

