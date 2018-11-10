//INFO: LIBRERIA TIME
//https://leantec.es/blog/42_Como-medir-el-tiempo-con-Arduino-y-la-librer%C3%AD.html
//https://www.prometec.net/time-arduino/

#include <Time.h>
#include <TimeLib.h>
//`hola

//variables de inicio reloj
int hora;
int minuto;
int segundo;
int dia;
int mes;
int any;
int menu;

//INFO LCD 16X2
//https://www.prometec.net/bus-i2c/
//https://www.zonamaker.com/arduino/modulos-sensores-y-shields/display-lcd-mediante-bus-i2c-twi-spi

#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
//variable con la dirección de nuestro display.
byte dir = 0x27;   
LiquidCrystal_I2C lcd(0x27,2, 1, 0, 4, 5, 6, 7);//ignorar, parametros para funcionar moduloi2c

//INFO PULLUP
//https://www.arduino.cc/en/Tutorial/InputPullupSerial





void setup()
{   
  Serial.begin(115200);//Inicializamos el puerto serie.
  //Anotamos la hora y la fecha desde la que nuestro programa empezará a contar.
  //Formato: hora, minutos, segundos, días, mes, año. Marca el inicio del reloj
  
  lcd.begin (16,2);                  //Inicializar el display con 16 caraceres 2 lineas
  lcd.setBacklightPin(3,POSITIVE);   //Esta instrucción establece que el pin 3 del display es el que enciende y apaga la luz de fondo.
  lcd.setBacklight(HIGH);            //encendemos la luz de fondo de nuestro display     
  pinMode(2, INPUT_PULLUP);
  
}
void loop() {   
int start = digitalRead(2);
if (start == LOW) {
   menu=1;
   setTime(hora, minuto, segundo, dia, mes, any);
}

if(menu==1){ 
    time_t t = now();//Declaramos la variable time_t t
    hora = hour(t);
    minuto = minute(t);
    segundo = second(t);
    //Serial.println(segundo);  
    //delay(1000);//Esperamos 1 segundo
    //(posicion,linea)
    lcd.home ();                       //Esta función coloca el cursor del display en la posición inicial (parte superior izquierda de la pantalla)
    lcd.print("Hora");
    lcd.setCursor ( 2, 1 );
    lcd.print(':');
    lcd.setCursor ( 5, 1 );
    lcd.print(':');
    
    if (segundo < 10){
      lcd.setCursor ( 7, 1 );
      lcd.print(segundo);
      lcd.setCursor ( 6, 1 );
      lcd.print(0);
    } else {
      lcd.setCursor ( 6, 1 );
      lcd.print(segundo);
    }
  if (minuto < 10){
      lcd.setCursor ( 4, 1 );
      lcd.print(minuto);
      lcd.setCursor ( 3, 1 );
      lcd.print(0);
    } else {
      lcd.setCursor ( 3, 1 );
      lcd.print(minuto);
    }
    if (hora < 10){
        lcd.setCursor ( 1, 1 );
        lcd.print(hora);
        lcd.setCursor ( 0, 1 );
        lcd.print(0);
      } else {
        lcd.setCursor ( 0, 1 );
        lcd.print(hora);
      }
}}
