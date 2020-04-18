///This is the list if inported Libribes that the user used to creeat the weather staion 
#include <dht.h>
#include <Servo.h> //this starts the Seveo libery   
#define dht_apin A0
Servo myservo;
int pos = 0;    // variable to store the servo position
int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;
int sensorValue;
dht DHT;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  Serial.begin (9600);  
  Serial.println ("Humidity and Temperature Sensor");
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object



}
void loop() {
  sensorValue = analogRead(2);       
  DHT.read11(dht_apin);
  int Photovalue = analogRead(A1);
  Serial.print("Current Humidity is ");
  Serial.print(DHT.humidity);
  Serial.print("% ");
  Serial.print("Temperature is ");
  Serial.print(DHT.temperature);
  Serial.print("C ");
  Serial.println();
  Serial.print("AirQua=");
  Serial.print(sensorValue, DEC);               // prints the value read
  Serial.println(" PPM"); // PPM stands for Parts per million,
  //this sesnor messure the amount of  fresh air. 

  if(DHT.temperature >=26){;
  RGB_color(225,0,0);//Red
  delay(1000);//delay of 1 second 
  }
  if ((DHT.temperature <=25 && DHT.temperature  >=20 )){;
  RGB_color(0,225,0);//Green
  delay(1000);//delay of 1 second 
  }

  if (DHT.temperature <=19){;
  RGB_color(0,191,255); //blue
  delay(1000);//delay of 1 second 
  }
 
  Serial.println("Analog value :");
  Serial.println(Photovalue);
  if ((Photovalue >= 790 && DHT.temperature >=26)){
  for (pos = 0; pos <= 180; pos += 1) { 
  }
    // in steps of 1 degree
    myservo.write(pos);             
    delay(20);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
  }
   delay(15);  

  
   

  
  
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
