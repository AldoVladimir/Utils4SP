function mpcPlot(t,x,plotInterval)
x_abs=abs(x);x_ph=angle(x);
  
if isnumeric(x)

    
   subplot(2,1,1)
   plot(t,x_abs,'o-','LineWidth',2)
   title('|X|')
   xlim([min(t)-0.5 max(t)+0.5])
   ylim([min(x_abs)-0.5 max(x_abs)+0.5])
   
   subplot(2,1,2)
   plot(t,x_ph,'or-','LineWidth',2)
   title('\angle X')
   xlim([min(t)-0.5 max(t)+0.5])
   ylim([min(x_ph)-0.5 max(x_ph)+0.5])
    
else 
   
   subplot(2,1,1)
   fplot(t,x_abs,plotInterval,'LineWidth',2)
   title('|X|')
   
   subplot(2,1,2)
   fplot(t,x_ph,plotInterval,'r','LineWidth',2)
   title('\angle X') 
end


end