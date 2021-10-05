function y=symbConv(x,h)
syms t tau ;
integrando=x(tau).*h(t-tau);
y=int(integrando,tau,-inf,inf);
end
