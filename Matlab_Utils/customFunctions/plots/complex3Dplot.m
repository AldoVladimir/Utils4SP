function complex3Dplot(t,x,limits)

x_Re=real(x); x_Im=imag(x);
  
if isnumeric(x)
    
ceros=@(t) t.*0;
plot3(t,x_Re,x_Im,'o-','LineWidth',2)
hold on
plot3(t,ceros(t),ceros(t),'k:','LineWidth',1.5)
xlabel('t')
zlabel('Im(x)')
ylabel('Re(x)')
grid on
hold off
    
else   
    
ceros=@(t)0*t;
fplot3(t,x_Re,x_Im,limits,'LineWidth',2)
hold on
fplot3(t,ceros(t),ceros(t),limits,'k:','LineWidth',1.5)
xlabel('t')
zlabel('Im(x)')
ylabel('Re(x)')
hold off

end


end