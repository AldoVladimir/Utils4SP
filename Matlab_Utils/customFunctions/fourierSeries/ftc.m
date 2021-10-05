function [ssin,ccos,c,b,a_0]=ftc(x_t,t_0,T,n)
syms  t

i=1:n;
w=2*pi/T;

b=zeros(1,length(i));   %Coeficientes de coseno
c=zeros(1,length(i));   %Coeficientes de seno
ccos=sym(zeros(1,length(i)));
ssin=sym(zeros(1,length(i)));

if isreal(x_t)
a_0=double((1/T).*integral(x_t,t,t_0,t_0+T));

 for k=1:n
ccos(k)=cos(k*w*t);
ssin(k)=sin(k*w*t);  
b(k)=integral(x_t*ccos(k),t,t_0,t_0+T);
c(k)=integral(x_t*ssin(k),t,t_0,t_0+T);

fprintf('Coeficiente k=%i \n',k)

 end
b=(2/T).*b;
c=(2/T).*c;
    
 else
a_0=double((1/T).*int(x_t,t,t_0,t_0+T));
 for k=1:n
b(k)=(2/T)*int(x_t*cos(k*w*t),t,t_0,t_0+T);
c(k)=(2/T)*int(x_t*sin(k*w*t),t,t_0,t_0+T);

ccos(k)=cos(k*w*t);
ssin(k)=sin(k*w*t);
fprintf('Coeficiente k=%i \n',k)
 end
 
b=double(b);
c=double(c);
    
      
end

end