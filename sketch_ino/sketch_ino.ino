// photocell attach to A0 on SUNFOUNDER MEGA2560
#define photocellPin 0
// Temprature / humidity sensor
#include <dht11.h>
DHT11 DHT11;

int led = 13;
#define DHT11PIN 52 // digital pin

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);   
}

void loop()
{
    // READ DATA
    Serial.print("DHT11, \t");
    //read the value returned from sensor
    int chk = DHT11.read(DHT11PIN);
    switch (chk) {
        case DHTLIB_OK:
            break;
        case DHTLIB_ERROR_CHECKSUM: 
            Serial.print("Checksum error,\t"); 
            break;
        case DHTLIB_ERROR_TIMEOUT: 
            Serial.print("Time out error,\t"); 
            break;
        default: 
            Serial.print("Unknown error,\t"); 
  	    break;
    }
   Serial.println();
   // DISPLAY DATA
   Serial.print("Temprature: ");
   Serial.print(DHT11.temperature);
   Serial.println(" C");

   Serial.print("Humutidiy: ");
   Serial.print(DHT11.humidity);
   Serial.println(" %"); 

   Serial.print("Photocell: ");
   Serial.println(analogRead(photocellPin));
   Serial.println();
   
   digitalWrite(led, HIGH);   
   delay(1500);
   digitalWrite(led, LOW);    
}
