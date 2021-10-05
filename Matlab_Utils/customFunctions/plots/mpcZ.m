function mpcZ(F,limits)

syms z w s 
W=0:0.01:2*pi;
x=imag(exp(1i*W)); y=real(exp(1i*W));

H=subs(F,z,s+1i*w);
X=double(subs(F,z,exp(1i*W)));


figure
fsurf(w,s,20*log10(abs(H)),limits)
hold on
plot3(x,y,20*log10(abs(X)),'r','LineWidth',3)
xlabel('i\omega')
ylabel('\sigma')
zlabel('|H| (dB)')
zlim([-60 60])
caxis([-60 60])
legend('Z','DTFT')
set(gca,'XDir','reverse')
hold off

figure
fsurf(w,s,angle(H),limits)
hold on
plot3(x,y,angle(X),'r','LineWidth',3)
xlabel('i\omega')
ylabel('\sigma')
zlabel('\angle (rad)')
set(gca,'XDir','reverse')
legend('Z','DTFT')
hold off

end