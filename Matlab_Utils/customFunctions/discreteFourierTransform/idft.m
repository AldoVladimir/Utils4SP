function x=idft(X)

N=length(X);

x=zeros(1,N);
x_part=zeros(1,N);

for n=0:N-1
    for k=0:N-1
    x_part(k+1)=X(k+1)*exp(1i*2*pi*n*k/N);
    end
    x(n+1)=sum(x_part);
end
x=(1/N)*x;

end

