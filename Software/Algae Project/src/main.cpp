/**
 * @file main.cpp
 * @author Sebastian Schroder, Adam Scicluna
 * @brief Main file, to run either select the main or mainmega environments inside platformio
 * main may not run due to the large size of the menu inside @file menu.h
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// Including necessary libraries, including self-created consisting other information
#include <Wire.h>
#include <global_variables.h>
#include <Arduino.h>
#include <IRremote.h> //this needs to be included in a .cpp file, IDK why it doesn't work in a header file

// Function Declarations
void Update_Sensor_State();
void Update_Control_State();

// Sensor variable intialisations
DS18B20 TempSensor1(TSensorPin1);
DS18B20 TempSensor2(TSensorPin2);
SEN0311 Sonar1(SonarRXPin,SonarTXPin);
// NewPing Sonar1(SSensorPin1,SonarEchoPin,400);
// NewPing Sonar2(SSensorPin2,SonarEchoPin,400);
IRrecv irrecv(IRRXPin);
DRI0050 PumpController(PumpTxPin,PumpRxPin);

// Setup loop runs once - for intialisation of Serial, LCD, and I/O Pins
void setup() {
  
  // Initialise Serial at 9600 BAUD Rate
  Serial.begin(9600);

  // Start LCD and IR Receiver
  Serial.println("Starting Up");
  delay(100);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  // lcd.begin(16,2);
  TopMenu.begin(display,displayValue);
  PumpController.setPwmFreq(10);
  PumpController.setPwmDuty(0);
  irrecv.enableIRIn(); // starts interrupt for IR receiver
  // if you want to change values here in code, then comment out the retrieve call and save the changes to the arduino
  // rom_manager.Retrieve();

  // Initialise PinMode for the Solenoid Valve Relay COM Port
  pinMode(SolanoidPin1,OUTPUT);

}

// Loop function - runs continously unless interrupted
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


/*
  Function Defintion: Sensor Updates
  Purpose: Takes Sensor readings, adds them to a cyclic array, and averages
           the array (currently set to store the last 10 readings) to print
           to LCD screen.
*/
void Update_Sensor_State(){
  lastSensorUpdate = millis();
  Serial.println("Reading Sensors");
  Serial.print("sonar: ");
  Serial.println(Sonar1.get_dist());

  Temp1[Cyclic_Array_Index] = (int)TempSensor1.readTempC();
  Temp2[Cyclic_Array_Index] = (int)TempSensor2.readTempC();
  SonarDist1[Cyclic_Array_Index] = (int)Sonar1.get_dist();
  // IRDist2[Cyclic_Array_Index] = Sonar2.get_dist(); //! need to swap to using the IR object
  Cyclic_Array_Index++;
  Temp1Average = Average_Array(Temp1,Cyclic_Array_Size);
  Temp2Average = Average_Array(Temp2,Cyclic_Array_Size);
  SonarAverage = Average_Array(SonarDist1,Cyclic_Array_Size);
  if(Cyclic_Array_Index>=Cyclic_Array_Size){Cyclic_Array_Index=0;}
}

/*
  Function Definition: Update state of controls (pump + solenoid valve)
  Purpose: Based on the sensor readings, and the set pump flow-rate, this function
           assigns a number, also known as a 'state' to each of the pump and
           solenoid valve to determine its current operation (e.g. on or off).
*/
void Update_Control_State()
{
  lastStateUpdate=millis();
  Serial.print("Pumpstate: ");
  Serial.print(PumpState);
  Serial.print(" , SolanoidState: ");
  Serial.println(SolanoidState);
  if(PumpState != prevPumpState)
  {
    prevPumpState=PumpState;
    if(PumpState==Control_State::Off)
    {  
      // if the pumpstate is off then turn off the pump pwm controller
      PumpController.setPwmEnable(PWM_DISENABLE);
      //digitalWrite(SolanoidPin2,LOW); //this is
      Serial.println("Pump Off");           
    }

    if(PumpState==Control_State::Manual)
    { 
      // if the state is set to manual, 
      PumpController.setPwmDuty(manual_dutycycle.var);
      PumpController.setPwmEnable(PWM_ENABLE);
      Serial.print("Pump On, duty Cycle: ");
      Serial.println(manual_dutycycle.var);
      //digitalWrite(SolanoidPin2,HIGH);
    }           
  }

  if(SolanoidState!=prevSolanoidState)
  {
    prevSolanoidState=SolanoidState;
    if(SolanoidState==Control_State::Off)
    {
      //digitalWrite(SolanoidPin1,LOW);
      //digitalWrite(SolanoidPin2,LOW);
      //digitalWrite(26,LOW);
      digitalWrite(28,LOW);
      Serial.println("Solenoid Closed");
    }
    else if(SolanoidState==Control_State::Manual)
    {
      //digitalWrite(SolanoidPin1,HIGH);
      //digitalWrite(SolanoidPin2,HIGH);
      //digitalWrite(26,HIGH);
      digitalWrite(28,HIGH);
      Serial.println("Solenoid Open");
    }       
  }


  if(SolanoidState==Control_State::Automatic)
  {
          
  }


  if(PumpState==Control_State::Automatic)
  {

  }
}


