

#include <Arduino.h>
#include <IRremote.h>
#include <AlgaePanelRemote.hpp>

const int recv_pin = 11;
IRrecv irrecv(recv_pin);

void setup(){
    
    Serial.begin(9600);
    irrecv.enableIRIn();
    irrecv.blink13(true);
Serial.println("Starting IR sensor test");
}

void loop(){
    if(irrecv.decode()){
        Serial.println(irrecv.decodedIRData.command);
        // irrecv.printIRResultRawFormatted(&Serial);
        
        irrecv.resume();
    }
}