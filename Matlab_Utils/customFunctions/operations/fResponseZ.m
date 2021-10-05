function H=fResponseZ(b,a)
syms w
k=length(b)-1:-1:0;
l=length(a)-1:-1:0;
H=sum(b.*(exp(-1i*k*W)))/sum(a.*(exp(-1i*l*w)));
end

