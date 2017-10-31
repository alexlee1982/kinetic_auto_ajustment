function [ J ] = F_J_z( th )
% UNTITLED3 此处显示有关此函数的摘要
%   此处显示详细说明


dgree=pi/180;

th1=th(1)*dgree;
th2=th(2)*dgree;
th3=th(3)*dgree;
th4=th(4)*dgree;
th5=th(5)*dgree;
th6=th(6)*dgree;



J(1,1) =0;
 
 
J(1,2) =300*cos(th3)*sin(th2) - 20*cos(th2)*cos(th3) - 300*cos(th2)*sin(th3) - 300*cos(th2) - 20*sin(th2)*sin(th3) - 100*cos(th5)*(cos(th2)*sin(th3) - cos(th3)*sin(th2)) - 100*cos(th4)*sin(th5)*(cos(th2)*cos(th3) + sin(th2)*sin(th3));
 
 
J(1,3) =20*cos(th2)*cos(th3) + 300*cos(th2)*sin(th3) - 300*cos(th3)*sin(th2) + 20*sin(th2)*sin(th3) + 100*cos(th5)*(cos(th2)*sin(th3) - cos(th3)*sin(th2)) + 100*cos(th4)*sin(th5)*(cos(th2)*cos(th3) + sin(th2)*sin(th3));
 
 
J(1,4) =-100*sin(th4)*sin(th5)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));
 
 
J(1,5) =100*sin(th5)*(cos(th2)*cos(th3) + sin(th2)*sin(th3)) + 100*cos(th4)*cos(th5)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));
 
 
J(1,6)  =0;


J(1,7) =100*sin(th4)*sin(th5);
 
 
J(1,8) =100*cos(th2)*sin(th4)*sin(th5);
 
 
J(1,9) =100*sin(th4)*sin(th5)*(cos(th2)*cos(th3) + sin(th2)*sin(th3));
 
 
J(1,10) =-100*cos(th5)*sin(th4)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));
 
 
J(1,11) =-100*sin(th4)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));
 

J(1,12) =0;

J(1,13) =0;
 
J(1,14) =-sin(th2);

J(1,15) =cos(th2)*sin(th3) - cos(th3)*sin(th2);
 
 
J(1,16)=cos(th4)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));
 
 
J(1,17) =sin(th5)*(cos(th2)*cos(th3) + sin(th2)*sin(th3)) + cos(th4)*cos(th5)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));
 
 
J(1,18) =cos(th6)*(sin(th5)*(cos(th2)*cos(th3) + sin(th2)*sin(th3)) + cos(th4)*cos(th5)*(cos(th2)*sin(th3) - cos(th3)*sin(th2))) - sin(th4)*sin(th6)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));
 
J(1,19) =1;

 
J(1,20) =0;
 
 
J(1,21) =0;
 
 
J(1,22) =cos(th2)*cos(th3) + sin(th2)*sin(th3);
 
 
J(1,23) =sin(th4)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));
 
 
J(1,24) =cos(th5)*(cos(th2)*cos(th3) + sin(th2)*sin(th3)) - cos(th4)*sin(th5)*(cos(th2)*sin(th3) - cos(th3)*sin(th2));



end

