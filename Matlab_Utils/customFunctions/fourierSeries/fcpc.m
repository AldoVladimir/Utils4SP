function [pCos,phase,A]=fcpc(x_t,t_0,T,n)
syms  t

i=1:n;
w=2*pi/T;

b=zeros(1,length(i));   %Coeficientes de coseno
c=zeros(1,length(i));   %Coeficientes de seno

pCos=sym(zeros(1,length(i)));


a_0=double((1/T).*int(x_t,t,t_0,t_0+T));

 for k=1:n
b(k)=(2/T)*int(x_t*cos(k*w*t),t,t_0,t_0+T);
c(k)=(2/T)*int(x_t*sin(k*w*t),t,t_0,t_0+T);

fprintf('Coeficiente k=%i \n',k)
 end

A=sqrt(b.^2+c.^2);phase=atan2(-c,b);
 for k=1:n
pCos(k)=cos(k*w*t+phase(k));
 end
 
 
%Le agrego el termino a_0 a los coeficientes
phase=[0 phase]; A=[a_0 A]; pCos=[1 pCos];

end








