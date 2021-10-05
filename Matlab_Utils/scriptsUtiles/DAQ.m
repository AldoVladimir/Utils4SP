%% Setup del puerto serie
%Búsqueda de todos los puertos serie
serialportlist

%Asignar un objeto serial y su tasa de baudios
s=serialport("/dev/ttyUSB0",115200)
configureTerminator(s,"LF")

%% Setup de la captura
figure
%Crea objeto de línea animada
h=animatedline;

%Coloca líneas paralelas al plot
ax=gca;
ax.YGrid='on';

%Indicador para seguir leyendo
continueRead=true;

%Nombre de la variable
name="analogRead";
%Tiempo durante el cual se va a medir
measureTime=seconds(10);
%Longitud de la lectura
numChars=6; %Número de caracters+1
numReads=40; %cantidad de numeros por lectura

%% Lectura y ploteo
%Leera y ploteará mientras continueRead sea verdadero
%t=(0:numReads-1)';
%n=0;
%Libera el buffer de Matlab para puerto serial
flush(s);
%Obtiene la fecha del sistema y la guarda
startTime=datetime('now');

%while 1 %Grabado infinito  
while continueRead  %Grabado con tiempo fijo
    
   %Lectura del valor actual del sensor   
   %data=read(s,(numReads)*numChars,'char');
   data=readline(s);
   data=str2num(data);
      
   %Añade los puntos de tiempo y datos a la linea animada
   %addpoints(h,t,data);
   
   %t=t+numReads;
   
   %Diferencia de tiempo
   t=datetime('now')-startTime;   
   addpoints(h,datenum(t),data);
   
   %Ajusta los limites de x
   %ax.XLim=[t(end)-1000 t(end)];
   %ax.XLim=datenum([t(end)-5 t(end)]);
   %Coloca un formato de fechas al eje x
   datetick('x','keeplimits');
   
   %Actualiza toda la información a la linea animada
   drawnow
   %Revisa si aún debe seguir grabando
   continueRead=t<=measureTime;
   %n=n+1;
   %Momento final de la muestra
   endTime=datetime('now');
end

%% Guardado de datos

%Momento final de la muestra
%endTime=datetime('now');

%Obtención de los datos desde la linea animada
[timeLogs,dataPoints] = getpoints(h);


%Vector de tiempo total
time=startTime:(endTime-startTime)/(numel(timeLogs)-1):endTime;
Ts=seconds(endTime-startTime)/numel(timeLogs);
fs=1/Ts;

%Liberar memoria de todas las variables de lectura en tiempo real
clear ax continueRead data endTime measureTime h t timeLogs

%% Ploteo de la señal capturada

figure
plot(time,dataPoints)
%xlabel('Tiempo')
ylabel(name+"[Adim]")

%% Guardar en ASCII
data=table(time',dataPoints','VariableNames',["Fecha" name+" fs:"+fs+"Hz"]);
writetable(data,"./Datasets/"+datestr(startTime)+"_"+name);
