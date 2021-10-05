function [ee,a]=fcc(x_t,t_0,T,n)
syms  t
i=-n:n;
w=2*pi/T;

a=zeros(1,length(i));
ee=sym(zeros(1,length(i)));



 for k=-n:n
a(k+n+1)=(1/T)*int(x_t*exp(-1i*k*w*t),t,t_0,t_0+T);
ee(k+n+1)=exp(1i*k*w*t);
fprintf('Coeficiente k=%i \n',k)
 end
 a=double(a);
 
end