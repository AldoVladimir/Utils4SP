function x=pT(t,t_0,width)
x=heaviside(t-t_0)-heaviside(t-(t_0+width+1));
end