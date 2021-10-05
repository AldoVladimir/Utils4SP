function [ny,y]=discConv(nx,x,nh,h)

dt=nx(2)-nx(1);
ny=nx(1)+nh(1):dt:nx(end)+nh(end);
y=conv(x,h).*dt;

end