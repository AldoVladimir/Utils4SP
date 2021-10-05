char var[4];

void setup() {
   Serial.begin(115200);
   pinMode(LED_BUILTIN, OUTPUT);
   //Serial.print("Test 1");Serial.print('\t');Serial.print("Fecha: 2020.12.30");
   //Serial.print('\n');Serial.print('\n');
   //Serial.print("Temp[°C]"); Serial.print('\n');
}

void loop() {
  //digitalWrite(LED_BUILTIN,HIGH);
  sprintf(var,"%03d",analogRead(A0));
  Serial.println(var);
  //digitalWrite(LED_BUILTIN,LOW);
  delay(1);
}
