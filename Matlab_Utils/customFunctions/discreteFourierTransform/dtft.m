function X=dtft(x)
syms omega;
n=0:numel(x)-1;
w=omega;
X=x.*exp(-1i*w*n);
X=sum(X);
end