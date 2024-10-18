#include "BluetoothSerial.h" 

BluetoothSerial SerialBT;    

const int ledPin = 2;       
void setup() {
  Serial.begin(115200);      
  SerialBT.begin("bt");  
  pinMode(ledPin, OUTPUT);    
  digitalWrite(ledPin, LOW);  
  
  
  delay(2000);
  Serial.println("Bluetooth aktif, menunggu menerima pesan...");
}

void loop() {
  if (SerialBT.available()) {         
    char receivedChar = SerialBT.read();  
    Serial.print("Data diterima: ");
    Serial.println(receivedChar);    

    if (receivedChar == '1') {        
      digitalWrite(ledPin, HIGH);     
      Serial.println("LED ON");
    }
    else if (receivedChar == '2') {  
      digitalWrite(ledPin, LOW);     
      Serial.println("LED OFF");
    }
  }
}
