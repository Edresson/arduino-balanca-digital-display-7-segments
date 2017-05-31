#include "HX711.h"
#define DOUT  A1
#define CLK  A0

#include "TimerOne.h"
 

HX711 balanza(DOUT, CLK);

             //a,b,c,d,e,f,g,pt
int num[10][8]={
                {1,1,1,1,1,1,0,0},//0
                {0,1,1,0,0,0,0,0},//1
                {1,1,0,1,1,0,1,0},//2
                {1,1,1,1,0,0,1,0},//3
                {0,1,1,0,0,1,1,0},//4
                {1,0,1,1,0,1,1,0},//5
                {1,0,1,1,1,1,1,0},//6
                {1,1,1,0,0,0,0,0},//7
                {1,1,1,1,1,1,1,0},//8
                {1,1,1,1,0,1,1,0} //9
               };

               
float valor =   1.6898;
                           
void setup(){

  
 
  balanza.set_scale((1409746.50/55 )); // estabelece o fator de calibração deve ser pego atravez
  
  
  balanza.tare(100);  //peso atual é considerado Tara.
  Timer1.initialize(500000);         // initialize timer1, and set a 1/2 second perio            // setup pwm on pin 9, 50% duty cycle
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
  pinMode(A5,OUTPUT); //negativos
  pinMode(A4,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT); 
  pinMode(6,OUTPUT);// display
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);//ponto
 
}

void callback()
{
 
  
  valor =  balanza.get_units(1);
  if(valor < 0) valor = 0.00;
  //Serial.println(valor);
  
}
void loop(){
      
      //delay(1);
      
      //valor =   valor+ 1;
            
  
      
       mostrar(valor);
     
}

void mostrar(float valor){       

    int a = valor/100;
      int b = (valor -(a*100))/10;    
      int c = (valor -(a*100 + b*10));
      int d = (((float)valor -((float)a*100 + (float)b*10 + (float)c))*10);
      int e = (((float)d -((float)a*100 + (float)b*10 + (float)c + (float)d))*10);  

    
     delay(3); 
    digitalWrite(A5,0);
    digitalWrite(A4,1);
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(6,num[a][0]);
    digitalWrite(7,num[a][1]);
    digitalWrite(8,num[a][2]);
    digitalWrite(9,num[a][3]);
    digitalWrite(10,num[a][4]);
    digitalWrite(11,num[a][5]);
    digitalWrite(12,num[a][6]);
    digitalWrite(13,0);
    delay(3);
    digitalWrite(A5,1);
    digitalWrite(A4,0);
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);  
    digitalWrite(6,num[b][0]);
    digitalWrite(7,num[b][1]);
    digitalWrite(8,num[b][2]);
    digitalWrite(9,num[b][3]);
    digitalWrite(10,num[b][4]);
    digitalWrite(11,num[b][5]);
    digitalWrite(12,num[b][6]);
    digitalWrite(13,0);
    delay(3); 
    digitalWrite(A5,1);
    digitalWrite(A4,1);
    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(6,num[c][0]);
    digitalWrite(7,num[c][1]);
    digitalWrite(8,num[c][2]);
    digitalWrite(9,num[c][3]);
    digitalWrite(10,num[c][4]);
    digitalWrite(11,num[c][5]);
    digitalWrite(12,num[c][6]);
    digitalWrite(13,1);
    delay(3); 
    digitalWrite(A5,1);
    digitalWrite(A4,1);
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,1);
    digitalWrite(6,num[d][0]);
    digitalWrite(7,num[d][1]);
    digitalWrite(8,num[d][2]);
    digitalWrite(9,num[d][3]);
    digitalWrite(10,num[d][4]);
    digitalWrite(11,num[d][5]);
    digitalWrite(12,num[d][6]);
    digitalWrite(13,0);
    delay(3); 
    digitalWrite(A5,1);
    digitalWrite(A4,1);
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,0);
    digitalWrite(6,num[e][0]);
    digitalWrite(7,num[e][1]);
    digitalWrite(8,num[e][2]);
    digitalWrite(9,num[e][3]);
    digitalWrite(10,num[e][4]);
    digitalWrite(11,num[e][5]);
    digitalWrite(12,num[e][6]);
    digitalWrite(13,0);  
    
}






































































