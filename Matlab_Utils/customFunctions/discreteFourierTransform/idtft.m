function x = idtft(X,N)
syms omega
w=omega;
%N=numel(X)
x=zeros(1,N);

for n=0:N-1
integrando=X*exp(1j*2*pi*n/N) 
x(n+1)=(1/N)*int(integrando,w,0,pi)
end

end

