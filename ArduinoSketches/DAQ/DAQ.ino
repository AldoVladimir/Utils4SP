char var[4];

void setup() {
   //-Inicializa la comunicación serial
   Serial.begin(115200);   

   //-Envía un encabezado en las lecturas del puerto serial
   //-Se recomienda usarlo si se hará una captura desde la terminal
   //Serial.print("Test 1 \t");Serial.println("Fecha: 2021.10.13");
   //Serial.print('\n');
   //Serial.println("Tension [V]");
}

void loop() {
  
  //-Escribe la lectura del pin A0 directo al serial
  //Serial.println(analogRead(A0));

  //-Escribe una variable numérica en un "char" de ancho fijo
  //-Este es el que debe usarse con el script de matlab  
  sprintf(var,"%03d",analogRead(A0));
  Serial.println(var);
  

  //-Controla la frecuencia de discretizacion
  delay(100);
}
