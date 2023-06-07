/**
 * @file main.cpp
 * @author Sebastian Schroder
 * @brief Main file, to run either select the main or mainmega environments inside platformio
 * main may not run due to the large size of the menu inside @file menu.h
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <Wire.h>
#include <global_variables.h>
#include <Arduino.h>
#include <IRremote.h> //this needs to be included in a .cpp file, IDK why it doesn't work in a header file

void Update_Sensor_State();
void Update_Control_State();


  DS18B20 TempSensor1(TSensorPin1);
  DS18B20 TempSensor2(TSensorPin2);
  SEN0311 Sonar1(SSensorPin1,SonarEchoPin);
  // NewPing Sonar1(SSensorPin1,SonarEchoPin,400);
  // NewPing Sonar2(SSensorPin2,SonarEchoPin,400);
  IRrecv irrecv(IRRXPin);
  DRI0050 PumpController(PumpTxPin,PumpRxPin);




void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);

  // while(!Serial){;}
  Serial.println("Starting Up");
  delay(100);
  lcd.init();
  lcd.backlight();
  // lcd.begin(16,2);
  TopMenu.begin(display,displayValue);
  PumpController.setPwmFreq(10);
  PumpController.setPwmDuty(0);
  irrecv.enableIRIn(); // starts interrupt for IR receiver
  // if you want to change values here in code, then comment out the retrieve call and save the changes to the arduino
  // rom_manager.Retrieve();
  pinMode(SolanoidPin1,OUTPUT);
  pinMode(SolanoidPin2,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);

}

void loop() {


// ----------------------------------------     UI      ---------------------------------------------------------

  if(irrecv.decode()){ //if IR receiver is picking up something
      if(Menu_IR_Input(irrecv.decodedIRData.command)){// if the response is a recognised command delay to prevent multiple commands read
        delay(20);
        irrecv.printIRResultMinimal(&Serial);
      irrecv.resume();
    }
  }
  if(Serial.available()){
    Menu_Serial_Input(Serial.read());
  }

//--------------------------------------------------      Sensor Data     ----------------------------------------------------------
  if(millis()-lastSensorUpdate >=SENSOR_RATE){Update_Sensor_State();}
//----------------------------------------------------    Control   -----------------------------------------------
  if(millis()-lastStateUpdate >= STATE_RATE){Update_Control_State();}
}







void Update_Sensor_State(){
  lastSensorUpdate = millis();
  Serial.println("Reading Sensors");
  Serial.print("sonar: ");
  Serial.println(Sonar1.get_dist());

  Temp1[Cyclic_Array_Index] = (int)TempSensor1.readTempC();
  Temp2[Cyclic_Array_Index] = (int)TempSensor2.readTempC();
  SonarDist1[Cyclic_Array_Index] = Sonar1.get_dist();
  // IRDist2[Cyclic_Array_Index] = Sonar2.get_dist(); //! need to swap to using the IR object
  Cyclic_Array_Index++;
  Temp1Average = Average_Array(Temp1,Cyclic_Array_Size);
  Temp2Average = Average_Array(Temp2,Cyclic_Array_Size);
  if(Cyclic_Array_Index>=Cyclic_Array_Size){Cyclic_Array_Index=0;}
}


void Update_Control_State(){
  lastStateUpdate=millis();
 Serial.print("Pumpstate: ");
    Serial.print(PumpState);
    Serial.print(" , SolanoidState: ");
    Serial.println(SolanoidState);
      lastStateUpdate=millis();
      if(PumpState != prevPumpState){
        prevPumpState=PumpState;
            if(PumpState==Control_State::Off){  // if the pumpstate is off then turn off the pump pwm controller
              PumpController.setPwmEnable(PWM_DISENABLE);
              //digitalWrite(SolanoidPin2,LOW); //this is
              Serial.println("Pump Off");
              
            }
            if(PumpState==Control_State::Manual){ // if the state is set to manual, 
              PumpController.setPwmDuty(manual_dutycycle.var);
              PumpController.setPwmEnable(PWM_ENABLE);
              Serial.print("Pump On, duty Cycle: ");
              Serial.println(manual_dutycycle.var);
              //digitalWrite(SolanoidPin2,HIGH);
            }
            
        }
      if(SolanoidState!=prevSolanoidState){
        prevSolanoidState=SolanoidState;
        if(SolanoidState==Control_State::Off){
          digitalWrite(SolanoidPin1,LOW);
          digitalWrite(SolanoidPin2,LOW);
          digitalWrite(26,LOW);
          digitalWrite(28,LOW);
          Serial.println("Solenoid Closed");
        }
        if(SolanoidState==Control_State::Manual){
          digitalWrite(SolanoidPin1,HIGH);
          digitalWrite(SolanoidPin2,HIGH);
          digitalWrite(26,HIGH);
          digitalWrite(28,HIGH);
          Serial.println("Solenoid Open");
        }
        
      }


      if(SolanoidState==Control_State::Automatic){
          
        }


        if(PumpState==Control_State::Automatic){

      }



}


