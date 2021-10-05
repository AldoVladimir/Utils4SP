const int hLength=18, maxVal=hLength-1;
//double h[hLength]={0,0.333,0.666,1,0.666,0.333,0};
double h[hLength]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
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
    y=y+x[k]*h[maxVal-k];
  }
//-----------------------------------

Serial.print(x[maxVal],0);Serial.print('\t');
Serial.print(y,0);Serial.print('\n');
//digitalWrite(LED_BUILTIN, LOW);
delay (100);
}
