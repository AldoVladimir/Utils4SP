const int hLength=21, maxVal=hLength-1;
const double h[hLength]={0,0.309,0.587,0.809,0.951,1,0.951,0.809,0.587,0.309,0,-0.309,-0.587,-0.809,-0.951,-1,-0.951,-0.809,-0.587,-0.309,0};
double x[hLength];

double y; 

int analogPin=A1;       //Pin Analógico


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); 
}

void loop() {
//digitalWrite(LED_BUILTIN, HIGH); 

//Retrasa todos los valores de x[n]-- 
  for (int n=0; n<maxVal; n++) { 
    x[n]=x[n+1];
  } 
//-----------------------------------

x[maxVal]= analogRead(analogPin);


//Convolucion------------------------
y=0;
  for (int k=0; k<=maxVal; k++){
    y=y+x[k]*h[k];
  }
//-----------------------------------

Serial.print(x[maxVal],0);Serial.print('\t');
Serial.print(y,0);Serial.print('\n');
//digitalWrite(LED_BUILTIN, LOW);
delay (100);
}
