// 5k ohm pull up resistor is used on the data line.
// Sensor operates at 5VDC.
// Data line connects to Arduino Uno pin 3.
#include<SoftwareSerial.h>
#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 2
SoftwareSerial s(4,6);
// Sensor calibration. Start with 0 for each.
const int HumidityCorrection = -10;          // -10 worked with my sensor.
const int CelsiusTemperatureCorrection = 2;  // 2 worked with my sensor.

const float FahrenheitTemperatureCorrection = CelsiusTemperatureCorrection * 1.8;

// Update the serial display every 60 seconds.
const float UpdateSerialDisplay = 60000;

// Celsius to Fahrenheit conversion.
double Fahrenheit(double celsius){
  return 1.8 * celsius + 32;
}

void setup(){
 // s.begin(9600);
  Serial.begin(9600);
  // Minimum wait for good data recommended is 1 second.
  delay(2000);
  pinMode(3,OUTPUT);
  
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
}

void loop(){
  Serial.println("");
  int chk = DHT11.read(DHT11PIN);
  switch(chk){
    case DHTLIB_OK: 
      //Serial.println("OK"); 
      break;
    case DHTLIB_ERROR_CHECKSUM: 
      Serial.println("Read sensor: Checksum error"); 
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      Serial.println("Read sensor: Time out error"); 
      break;
    default: 
      Serial.println("Read sensor: Unknown error"); 
      break;
  }

  Serial.print("Humidity: ");
  Serial.print("\t");
  Serial.print(DHT11.humidity + HumidityCorrection);
 
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print("\t");
  Serial.print(DHT11.temperature + CelsiusTemperatureCorrection);
  Serial.println(" C");

  Serial.print("Temperature: ");
  Serial.print("\t");
 Serial.print(round(Fahrenheit(DHT11.temperature) + FahrenheitTemperatureCorrection));
  Serial.println(" F");
/*int temp1 = DHT11.temperature + CelsiusTemperatureCorrection;
int temp2 = DHT11.humidity + HumidityCorrection;
  if(s.available()>0)
  {
    s.write(temp1); 
     s.write(temp2); 
  }*/
  int x;
 
 if(s.available()>0)
 {
  x = s.read();
  if(x==0)
  {
    digitalWrite(3,LOW);
  }
  else
  {
    digitalWrite(3,HIGH);
  }
  
 }
}
