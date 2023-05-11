
#include <global_variables.h>
#include <Arduino.h>
#include <IRremote.h> //this needs to be included in a .cpp file, IDK why it doesn't work in a header file

  DS18B20 TempSensor1(TSensorPin1);
  DS18B20 TempSensor2(TSensorPin2);
  NewPing Sonar1(SSensorPin1,SonarEchoPin,400);
  NewPing Sonar2(SSensorPin2,SonarEchoPin,400);
IRrecv irrecv(IRRXPin);
DRI0050 PumpController(PumpTxPin,PumpRxPin);


void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial){;}
  Serial.println("Starting Up");
  lcd.begin(16,2);
  TopMenu.begin(display,displayValue);
  PumpController.setPwmFreq(10);
  PumpController.setPwmDuty(0);
  // if you want to change values here in code, then comment out the retrieve call and save the changes to the arduino
  // rom_manager.Retrieve();

}

void loop() {//! do not put anything here, task scheduler will take over


// ----------------------------------------     UI      ---------------------------------------------------------

if(irrecv.decode()){ //if IR receiver is picking up something
    Menu_IR_Input(irrecv.decodedIRData.command);
  }
if(Serial.available()){
  Menu_Serial_Input(Serial.read());
}

//--------------------------------------------------      Sensor Data     ----------------------------------------------------------

      Temp1 = (int)TempSensor1.readTempC();
      Temp2 = (int)TempSensor2.readTempC();
      SonarDist1 = Sonar1.ping_cm();
      SonarDist2 = Sonar2.ping_cm();



//----------------------------------------------------    Control   -----------------------------------------------
Serial.print("Current PunpState: ");
Serial.println(PumpState);

if(PumpState != prevPumpState){
  prevPumpState=PumpState;
      if(PumpState==Control_State::Off){  // if the pumpstate is off then turn off the pump pwm controller
        PumpController.setPwmEnable(PWM_DISENABLE);
        digitalWrite(SolanoidPin2,LOW);
        
      }
      if(PumpState==Control_State::Manual){ // if the state is set to manual, 
        PumpController.setPwmDuty(manual_dutycycle.var);
        PumpController.setPwmEnable(PWM_ENABLE);
        digitalWrite(SolanoidPin2,HIGH);
      }
      
  }
  if(SolanoidState!=prevSolanoidState){
    prevSolanoidState=SolanoidState;
    if(SolanoidState==Control_State::Off){
      digitalWrite(SolanoidPin1,LOW);
    }
    if(SolanoidState==Control_State::Manual){
      digitalWrite(SolanoidPin1,HIGH);
    }
    
  }


  if(SolanoidState==Control_State::Automatic){
      
    }


    if(PumpState==Control_State::Automatic){

  }
}