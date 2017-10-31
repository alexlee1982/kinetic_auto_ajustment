function [ J ] = F_J_y( th )
% UNTITLED2 此处显示有关此函数的摘要
%   此处显示详细说明

dgree=pi/180;

th1=th(1)*dgree;
th2=th(2)*dgree;
th3=th(3)*dgree;
th4=th(4)*dgree;
th5=th(5)*dgree;
th6=th(6)*dgree;



J(1,1) =100*cos(th1) + 300*cos(th1)*cos(th2) - 100*sin(th5)*(sin(th1)*sin(th4) - cos(th4)*(cos(th1)*sin(th2)*sin(th3) + cos(th1)*cos(th2)*cos(th3))) + 100*cos(th5)*(cos(th1)*cos(th2)*sin(th3) - cos(th1)*cos(th3)*sin(th2)) + 20*cos(th1)*sin(th2)*sin(th3) + 20*cos(th1)*cos(th2)*cos(th3) + 300*cos(th1)*cos(th2)*sin(th3) - 300*cos(th1)*cos(th3)*sin(th2);
J(1,2) =20*cos(th2)*sin(th1)*sin(th3) - 100*cos(th5)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1)) - 300*sin(th1)*sin(th2) - 20*cos(th3)*sin(th1)*sin(th2) - 300*sin(th1)*sin(th2)*sin(th3) + 100*cos(th4)*sin(th5)*(cos(th2)*sin(th1)*sin(th3) - cos(th3)*sin(th1)*sin(th2)) - 300*cos(th2)*cos(th3)*sin(th1);
J(1,3) =100*cos(th5)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1)) - 20*cos(th2)*sin(th1)*sin(th3) + 20*cos(th3)*sin(th1)*sin(th2) + 300*sin(th1)*sin(th2)*sin(th3) - 100*cos(th4)*sin(th5)*(cos(th2)*sin(th1)*sin(th3) - cos(th3)*sin(th1)*sin(th2)) + 300*cos(th2)*cos(th3)*sin(th1);
J(1,4) =100*sin(th5)*(cos(th1)*cos(th4) - sin(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1)));
J(1,5) =100*cos(th5)*(cos(th1)*sin(th4) + cos(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1))) - 100*sin(th5)*(cos(th2)*sin(th1)*sin(th3) - cos(th3)*sin(th1)*sin(th2));
J(1,6)  =0;
J(1,7) =300*cos(th1)*sin(th2) + 100*cos(th5)*(cos(th1)*sin(th2)*sin(th3) + cos(th1)*cos(th2)*cos(th3)) + 300*cos(th1)*sin(th2)*sin(th3) - 100*cos(th4)*sin(th5)*(cos(th1)*cos(th2)*sin(th3) - cos(th1)*cos(th3)*sin(th2)) + 300*cos(th1)*cos(th2)*cos(th3) - 20*cos(th1)*cos(th2)*sin(th3) + 20*cos(th1)*cos(th3)*sin(th2);
J(1,8) =300*cos(th1)*cos(th3) - 20*cos(th1)*sin(th3) + 100*sin(th5)*(sin(th1)*sin(th2)*sin(th4) - cos(th1)*cos(th4)*sin(th3)) + 100*cos(th1)*cos(th3)*cos(th5);
J(1,9) =300*cos(th1) + 100*cos(th1)*cos(th5) - 100*sin(th4)*sin(th5)*(cos(th2)*sin(th1)*sin(th3) - cos(th3)*sin(th1)*sin(th2));
J(1,10) =100*cos(th5)*(cos(th1)*cos(th4) - sin(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1)));
J(1,11) =100*cos(th1)*cos(th4) - 100*sin(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1));
J(1,12) =0;
J(1,13) =sin(th1);
J(1,14) =cos(th2)*sin(th1);
J(1,15) =sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1);
J(1,16)=cos(th1)*sin(th4) + cos(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1));
J(1,17) =cos(th5)*(cos(th1)*sin(th4) + cos(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1))) - sin(th5)*(cos(th2)*sin(th1)*sin(th3) - cos(th3)*sin(th1)*sin(th2));
J(1,18) =sin(th6)*(cos(th1)*cos(th4) - sin(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1))) + cos(th6)*(cos(th5)*(cos(th1)*sin(th4) + cos(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1))) - sin(th5)*(cos(th2)*sin(th1)*sin(th3) - cos(th3)*sin(th1)*sin(th2)));
J(1,19) =0;
J(1,20) =cos(th1);
J(1,21) =-cos(th1);
J(1,22) =cos(th3)*sin(th1)*sin(th2) - cos(th2)*sin(th1)*sin(th3);
J(1,23) =sin(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1)) - cos(th1)*cos(th4);
J(1,24) =- sin(th5)*(cos(th1)*sin(th4) + cos(th4)*(sin(th1)*sin(th2)*sin(th3) + cos(th2)*cos(th3)*sin(th1))) - cos(th5)*(cos(th2)*sin(th1)*sin(th3) - cos(th3)*sin(th1)*sin(th2));


end

