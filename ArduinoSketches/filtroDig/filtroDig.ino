//Orden del filtro
const int arrayLength=3;

double b[arrayLength]={0.1382,-0.2765,0.1382};
double a[arrayLength]={1.0000,0.7735,0.3939};

double z[arrayLength];

// Variable pivote
double sum; 
double x; 
double y=0;

int LED_BUILTIN=2;
//int analogPin=A1;       //Pin Analógico
const int analogPin=27;       //Pin Analógico

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT); 
  //Serial.print("Capture 1");Serial.print('\n');
  //Serial.print("Fecha: 2020.12.30");Serial.print('\n');
}


void loop() {
  //digitalWrite(LED_BUILTIN, HIGH);
x = analogRead(analogPin);


//Retrasa todos los valores de z[n]-- 
  for (int n=0; n<arrayLength-1; n++) { 
    z[n]=z[n+1];
  } 
//-----------------------------------


//Calcula el valor de z[n]----------- 
    sum=0;
      for (int k=1; k<arrayLength; k++ ){
        sum=a[k]*z[arrayLength-k-1]+sum;        
      }    
    z[arrayLength-1]=(1/a[0])*(-sum+x);
    //z[arrayLength-1]=(1/a[0])*(-sum+analogRead(analogPin));
//-----------------------------------

//Serial.print("z=["); 
//for (int k=0;k<arrayLength;k++){Serial.print(z[k]); Serial.print('\t');}
//Serial.print("]");
//Serial.print('\n');


  y=0;
  for (int l=0; l<arrayLength; l++) {
    y=b[l]*z[arrayLength-l-1]+y;
  }

Serial.print(x); Serial.print('\t'); 
Serial.println(y,0);

  
//digitalWrite(LED_BUILTIN, LOW);
delay (10);
}
