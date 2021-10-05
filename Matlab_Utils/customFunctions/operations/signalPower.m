function   P=signalPower(x_t,t_0,T)
syms t
    P=(1/T)*int(abs(x_t).^2,t,t_0,t_0+T);
    P=double(P);
end