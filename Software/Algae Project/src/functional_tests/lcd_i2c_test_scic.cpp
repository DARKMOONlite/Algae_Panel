/*
    This test does two things (all within setup loop):
    1. Gets the I2C Address of the LCD
        - changes depending on the manufacuturer of the IC chip on the I2C board

    2. Initialises the LCD with a simple 'Hello World' message.
*/

// Including required libraries
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

uint8_t address = 0;

uint8_t get_i2c_address(void);

// Setup loop - runs once
void setup() {
  // Initialise Wire and Serial  
  Wire.begin();
  Serial.begin(9600);

  while (!Serial); // Leonardo: wait for Serial Monitor
  Serial.println("\nI2C Scanner");

}

void loop() {
  address = get_i2c_address();

  LiquidCrystal_I2C lcd(address,16,2);  // set the LCD address for a 16 chars and 2 line display

  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
  
  lcd.setCursor(1,1);   //Move cursor to character 1 on line 1
  lcd.print("LCD I2C Test");

  delay(1000);
}

uint8_t get_i2c_address(void)
{
    int nDevices = 0;

  Serial.println("Scanning...");

  for (byte address = 1; address < 127; ++address) {
    // The i2c_scanner uses the return value of
    // the Wire.endTransmission to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");

      ++nDevices;

      return address;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      return address;
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
    return 0;
  } else {
    Serial.println("done\n");
  }
}
