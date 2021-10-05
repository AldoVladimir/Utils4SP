function mpcdBPlot(t,x,plotInterval)
x_abs=20*log10(abs(x));x_ph=angle(x);
  
if isnumeric(x)

    
   subplot(2,1,1)
   semilogx(t,x_abs,'o-','LineWidth',2)
   title('|X|')
   xlim([min(t)-0.5 max(t)+0.5])
   ylim([min(x_abs)-0.5 max(x_abs)+0.5])
   ylabel("dB")
   
   subplot(2,1,2)
   semilogx(t,x_ph,'or-','LineWidth',2)
   title('\angle X')
   xlim([min(t)-0.5 max(t)+0.5])
   ylim([min(x_ph)-0.5 max(x_ph)+0.5])
    
else 
   
   subplot(2,1,1)
   fplot(t,x_abs,plotInterval,'LineWidth',2)
   set(gca, 'XScale', 'log')
   title('|X|')
   ylabel("dB")
   
   subplot(2,1,2)
   fplot(t,x_ph,plotInterval,'r','LineWidth',2)
   set(gca, 'XScale', 'log')
   
   title('\angle X') 
end


end