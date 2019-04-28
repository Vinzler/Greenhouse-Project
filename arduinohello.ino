#include<SoftwareSerial.h>
SoftwareSerial myserial(5,6); //rx and tx
void setup() {
  // put your setup code here, to run once:
myserial.begin(9600);
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
int data=50;
if(myserial.available()>0)
{
  char c = myserial.read();
  if(c=='s')
  {
    myserial.write(data);
  }
}
}
