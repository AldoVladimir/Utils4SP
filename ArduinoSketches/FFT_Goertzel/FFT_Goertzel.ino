#include <math.h>
double pi=3.141592;

const int N=4096; //Número de términos
double x[N];    //Señal
double Xre;  //Espectro real
double Xim;  //Espectro imag
double w;    //Frecuencia dummy
double dt=1; //Periodo de discretizacion [ms]


//int analogPin=A1;       //Pin Analógico
int analogPin=27;       //Pin Analógico ESP32
double avg;

void setup() {
  Serial.begin(115200);
  //pinMode(LED_BUILTIN, OUTPUT); 
}

void loop() {

//Tomar la lectura------------
 for(int n=0;n<N;n++){
  //x[n]=(analogRead(analogPin)/10)-97; //Hay que centrarla en cero
  x[n]=(analogRead(analogPin)/10);
   delay(dt);
 }
//----------------------------


//Detrend--------------------
avg=0;
for(int n=0;n<N;n++){
  avg=x[n]+avg; 
 }
 
avg=avg/N;

for(int n=0;n<N;n++){
  x[n]=x[n]-avg;    
 }
//-----------------------

//Calculo Goertzel--------------
  for (int k=0;k<N;k++){
   w=2*pi*k/N; 
   
    //Cálculo de termino intermedios--
    double s[3]={0,0,0};    
    for(int n=0;n<N;n++){
    s[0]=s[1];s[1]=s[2];  
    s[2]=x[n]+2*cos(w)*s[1]-s[0];
    }
    //------------------------------
  Xre=s[2]-cos(w)*s[1];
  Xim=sin(w)*s[1];
  
Serial.print(x[k]);Serial.print('\t'); 
//Densidad de potencia espectral
Serial.print(10*log10((dt/1000)*(Xre*Xre+Xim*Xim)/N));Serial.print('\t');
//Fase
Serial.println(atan2(Xim,Xre));
}



}
