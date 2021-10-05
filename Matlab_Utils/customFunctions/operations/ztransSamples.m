function Z=ztransSamples(t,x)
syms z 
Z=sum(x.*z.^(-t));
end

