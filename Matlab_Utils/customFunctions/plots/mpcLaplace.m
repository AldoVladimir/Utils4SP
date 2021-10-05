function mpcLaplace(F,limits)
syms w s

H=subs(F,s,s+1i*w);
X=subs(F,s,1i*w);

figure
fsurf(w,s,20*log10(abs(H)),limits)
hold on
fplot3(w,@(s) s*0,20*log10(abs(X)),[limits(3) limits(4)],'r','LineWidth',3)
xlabel('i\omega')
ylabel('\sigma')
zlabel('|H| (dB)')
zlim([-60 60])
caxis([-60 60])
legend('Laplace','Fourier')
set(gca,'XDir','reverse')
hold off

figure
fsurf(w,s,angle(H),limits)
hold on
fplot3(w,@(s) s*0,angle(X),[limits(3) limits(4)],'r','LineWidth',3)
xlabel('i\omega')
ylabel('\sigma')
zlabel('\angle (rad)')
set(gca,'XDir','reverse')
legend('Laplace','Fourier')
hold off

end