function [ J ] = F_J_x( th )
% UNTITLED 此处显示有关此函数的摘要
%   此处显示详细说明
% 计算位置误差模型的雅克比矩阵


th1=th(1);
th2=th(2);
th3=th(3);
th4=th(4);
th5=th(5);
th6=th(6);




J(1,1) =300*cosd(th3)*sind(th1)*sind(th2) - 300*cosd(th2)*sind(th1) - 100*sind(th5)*(cosd(th1)*sind(th4) + cosd(th4)*(sind(th1)*sind(th2)*sind(th3) + cosd(th2)*cosd(th3)*sind(th1))) - 100*cosd(th5)*(cosd(th2)*sind(th1)*sind(th3) - cosd(th3)*sind(th1)*sind(th2)) - 300*cosd(th2)*sind(th1)*sind(th3) - 100*sind(th1) - 20*sind(th1)*sind(th2)*sind(th3) - 20*cosd(th2)*cosd(th3)*sind(th1);
J(1,2) =100*cosd(th4)*sind(th5)*(cosd(th1)*cosd(th2)*sind(th3) - cosd(th1)*cosd(th3)*sind(th2)) - 100*cosd(th5)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3)) - 300*cosd(th1)*sind(th2)*sind(th3) - 300*cosd(th1)*sind(th2) - 300*cosd(th1)*cosd(th2)*cosd(th3) + 20*cosd(th1)*cosd(th2)*sind(th3) - 20*cosd(th1)*cosd(th3)*sind(th2);
J(1,3) =100*cosd(th5)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3)) + 300*cosd(th1)*sind(th2)*sind(th3) - 100*cosd(th4)*sind(th5)*(cosd(th1)*cosd(th2)*sind(th3) - cosd(th1)*cosd(th3)*sind(th2)) + 300*cosd(th1)*cosd(th2)*cosd(th3) - 20*cosd(th1)*cosd(th2)*sind(th3) + 20*cosd(th1)*cosd(th3)*sind(th2);
J(1,4) =-100*sind(th5)*(cosd(th4)*sind(th1) + sind(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3)));
J(1,5) =- 100*cosd(th5)*(sind(th1)*sind(th4) - cosd(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3))) - 100*sind(th5)*(cosd(th1)*cosd(th2)*sind(th3) - cosd(th1)*cosd(th3)*sind(th2));
J(1,6)  =0;
J(1,7) =20*cosd(th2)*sind(th1)*sind(th3) - 100*cosd(th5)*(sind(th1)*sind(th2)*sind(th3) + cosd(th2)*cosd(th3)*sind(th1)) - 300*sind(th1)*sind(th2) - 20*cosd(th3)*sind(th1)*sind(th2) - 300*sind(th1)*sind(th2)*sind(th3) + 100*cosd(th4)*sind(th5)*(cosd(th2)*sind(th1)*sind(th3) - cosd(th3)*sind(th1)*sind(th2)) - 300*cosd(th2)*cosd(th3)*sind(th1);
J(1,8) =20*sind(th1)*sind(th3) - 300*cosd(th3)*sind(th1) + 100*sind(th5)*(cosd(th1)*sind(th2)*sind(th4) + cosd(th4)*sind(th1)*sind(th3)) - 100*cosd(th3)*cosd(th5)*sind(th1);
J(1,9) =- 300*sind(th1) - 100*cosd(th5)*sind(th1) - 100*sind(th4)*sind(th5)*(cosd(th1)*cosd(th2)*sind(th3) - cosd(th1)*cosd(th3)*sind(th2));
J(1,10) =-100*cosd(th5)*(cosd(th4)*sind(th1) + sind(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3)));
J(1,11) =- 100*cosd(th4)*sind(th1) - 100*sind(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3));
J(1,12) =0;
J(1,13) =cosd(th1);
J(1,14) =cosd(th1)*cosd(th2);
J(1,15) =cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3);
J(1,16)=cosd(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3)) - sind(th1)*sind(th4);
J(1,17) =- cosd(th5)*(sind(th1)*sind(th4) - cosd(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3))) - sind(th5)*(cosd(th1)*cosd(th2)*sind(th3) - cosd(th1)*cosd(th3)*sind(th2));
J(1,18) =- sind(th6)*(cosd(th4)*sind(th1) + sind(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3))) - cosd(th6)*(cosd(th5)*(sind(th1)*sind(th4) - cosd(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3))) + sind(th5)*(cosd(th1)*cosd(th2)*sind(th3) - cosd(th1)*cosd(th3)*sind(th2)));
J(1,19) =0;
J(1,20) =-sind(th1);
J(1,21) =sind(th1);
J(1,22) =cosd(th1)*cosd(th3)*sind(th2) - cosd(th1)*cosd(th2)*sind(th3); 
J(1,23) =cosd(th4)*sind(th1) + sind(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3));
J(1,24) =sind(th5)*(sind(th1)*sind(th4) - cosd(th4)*(cosd(th1)*sind(th2)*sind(th3) + cosd(th1)*cosd(th2)*cosd(th3))) - cosd(th5)*(cosd(th1)*cosd(th2)*sind(th3) - cosd(th1)*cosd(th3)*sind(th2));

end

