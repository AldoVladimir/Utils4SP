function H=fResponseS(b,a)
syms w
k=length(b)-1:-1:0;
l=length(a)-1:-1:0;
H=sum(b.*(1j*w).^k)/sum(a.*(1j*w).^l);
end