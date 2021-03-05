
//libraries necessary for the project that includes blynk app, esp8266 model, servo motor
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo; // creating object of servo motor
char auth[] = "aU2PtgZNMyYrYwadh6ZkohA_97N2g_ut"; // unique authorization key for the authentication
char ssid[] = "WIfi-name"; // name of the wifi required
char pass[] = "wifi-password"; // password of the wifi required

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); // blynk function provide with required arguments

  servo.attach(15); // NodeMCU D8 pin
  pinMode(D2,OUTPUT); // NodeMCU D2 pin assigned for buzzer
  
 }
void loop()
{
  Blynk.run();// to run the function through blynk app
 }
BLYNK_WRITE(V1)// run the code if signal is comming from virtual pin that is v1
{
servo.write(0);  // servo motor at 0 degree
delay(2500);        // get back to the position after 2.5 sec 
servo.write(90); // servo motor at 90 degree
delay(0); // 0 await
if(servo.read()==90){ // condition to beep the buzzer it the servo motor is at 90 degree rotation
  digitalWrite(D2,HIGH);
  delay(500);
  digitalWrite(D2,LOW); //Buzzer Pin
  delay(500);
  }
}
