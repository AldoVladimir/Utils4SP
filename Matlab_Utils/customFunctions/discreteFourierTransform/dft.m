function X=dft(x)

N=length(x);

X=zeros(1,N);
X_part=zeros(1,N);

for k=0:N-1
    for n=0:N-1
        X_part(n+1)=x(n+1).*exp(-1i*2*pi*n*k/N);  
    end
    X(k+1)=sum(X_part);
end
%Nota: El error es que la cuenta no empezaba en cero
%No causaba problemas al momento de almacenarlos, sino que ignoraba el
%armónico DC 
end
