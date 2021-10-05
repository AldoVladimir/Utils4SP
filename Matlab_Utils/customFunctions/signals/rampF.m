function x=rampF(t,t_0)
x=(t-t_0).*heaviside(t-t_0);
end