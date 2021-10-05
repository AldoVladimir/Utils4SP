// Agradecimientos a Rodrigo Alcántara por transcribir el código de la manera más óptima posible
// 2021.06.28_2:30
#include <math.h>
#define PI 3.14159265
int const N=256;

double x[N];
double X_Re[N];    
double X_Im[N];
double E[N];
double dt=10; //Periodo de discretizacion [ms]
int analogPin=27;       //Pin Analógico ESP32
double avg;

void setup(){
  Serial.begin(115200);
}

void loop() {

//Tomar la lectura------------
 for(int n=0;n<N;n++){
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


//Cálculo fft------  
  fft(x,X_Re,X_Im, N);
  fftComplex2Real(X_Re,X_Im, E, N);
//------------------

//Send Serial
for (int k=0;k<N;k++){
Serial.print(x[k]);Serial.print('\t'); 
Serial.println(10*log10((dt/1000)*E[k]/N));
}  
delay(1);
}



void fft_radix2(double* x, double* X_Re, double* X_Im, int N, int s) {

    // At the lowest level pass through (delta T=0 means no phase).
    if (N == 1) {
        X_Re[0] = x[0];
        X_Im[0] = x[0]; 
        return;
    }

    int k;
    double t_Re;
    double t_Im;
    int N_2 = N/2;
    int _2s = 2*s;

    // Cooley-Tukey: recursively split in two, then combine beneath.
    fft_radix2(x, X_Re, X_Im, N_2, _2s);
    fft_radix2(x+s, X_Re + N_2, X_Im + N_2, N_2, _2s);

    double _2pi_N = 2*PI/N;
    double sinw, cosw;
    double cosw_XRe_plus_sinw_XIm, cosw_XIm_minus_sinw_XRe;

    for (k = 0; k < N_2; k++) {

        cosw = cos(_2pi_N*k);
        sinw = sin(_2pi_N*k);
        cosw_XRe_plus_sinw_XIm  = cosw*X_Re[k + N_2] + sinw*X_Im[k + N_2];
        cosw_XIm_minus_sinw_XRe = cosw*X_Im[k + N_2] - sinw*X_Re[k + N_2];

        t_Re = X_Re[k];
        t_Im = X_Im[k];

        X_Re[k]       = t_Re + (cosw_XRe_plus_sinw_XIm);
        X_Im[k]       = t_Im + (cosw_XIm_minus_sinw_XRe);
        
        X_Re[k + N_2] = t_Re - (cosw_XRe_plus_sinw_XIm);
        X_Im[k + N_2] = t_Im - (cosw_XIm_minus_sinw_XRe);
    }
}

void fftComplex2Real(double* X_Re, double* X_Im, double* x, int N){
    int i;
    for(i=0; i<N; i++){
        x[i] = (X_Re[i]*X_Re[i] +  X_Im[i]*X_Im[i]);   // Dividir entre el ancho de BIN
    }
}

void fft(double* x, double* X_Re, double* X_Im, int N) {
    fft_radix2(x, X_Re, X_Im, N, 1);
}
