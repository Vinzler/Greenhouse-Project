#include<SoftwareSerial.h>
SoftwareSerial s(D6,D5);//rx and tx
int data;
void setup() {
  // put your setup code here, to run once:
   s.begin(9600);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  s.write("s");
  if(s.available())
  {
    data = s.read();
    Serial.println(data);
  }
 
}
