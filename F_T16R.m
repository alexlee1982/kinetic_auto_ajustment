function [ T ] = F_T16R( th )
%T16R 此处显示有关此函数的摘要
%   此处显示详细说明 计算实际矩阵，th为6维度行向量

T=AiR(th(1),1)*AiR(th(2),2)*AiR(th(3),3)*AiR(th(4),4)*AiR(th(5),5)*AiR(th(6),6);


end

