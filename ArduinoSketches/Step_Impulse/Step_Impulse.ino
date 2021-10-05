int analogPin=A1;  //Pin Analógico
double x[2];      //Guardará presente y futuro

void setup() {
  Serial.begin(500000);
  //pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(analogPin,INPUT);
}

void loop() {
x[1]=x[0];  
x[0]=analogRead(analogPin);

Serial.print(x[0]);Serial.print("\t"); 
Serial.print((x[0]-x[1])*2);Serial.print("\n");

delay(100);
}
