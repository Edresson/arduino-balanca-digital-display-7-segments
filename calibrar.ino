#include "HX711.h"

#define DOUT  A1 
#define CLK  A0

HX711 balanca(DOUT, CLK);

float mediaMovel(float xis) {
   static float media = 0.0;
   static int indice = 1;

   if (indice == 0 || indice == 33) {
       indice = 1;
       media = 0.0;
   }

   media = media + (xis - media) / indice++;

   return media;
}

void setup() {
  Serial.begin(9600);
  Serial.println(balanca.read());
  Serial.println("não coloque nenhum peso na balança ");
  Serial.println("Destarando...");
  balanca.set_scale(); 
  balanca.tare(100);  //peso atual é considerado como Tara.
  Serial.println("Coloque um peso conhecido");
  Serial.println("digite B para iniciar a leitura para encontrar o fator de calibração: ");
  
}
void Calibrar_balanca() {
  
  
  int i;
  float calib;
  float cal;
  for (i = 1; i <= 100; i++) {
    cal = balanca.get_value(10);
    Serial.println(cal);
    calib += cal;
    delay(10);

  }
  Serial.print("Fator de calibração:");
  
  Serial.println((mediaMovel(calib / 100)));
  Serial.println(" você deve dividir este valor pelo peso conhecido que voce colocou na balança")

}

String vel;
float a;
String d;
void loop() {
  

  vel  = Serial.readString();
  
  switch (vel[0]) {
    case 'B':
      Serial.println("iniciando calibração isso pode demorar alguns minutos");
      Calibrar_balanca();
      break;
  
  }
  delay(100);
  
  
}
