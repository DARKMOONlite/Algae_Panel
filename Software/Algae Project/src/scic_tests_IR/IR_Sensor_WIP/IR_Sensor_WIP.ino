/* INCLUDING LIBRARIES */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <math.h>
#include <LiquidCrystal.h>

/* DEFINING MACROS */
#define SENSOR_CHECK 10
#define LCD_UPDATE 500

/* INITIALISING LCD */
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/* Setting up global variables for time */
volatile long unsigned int milliseconds = 0;
volatile long unsigned int secondsUnit = 0;
volatile long unsigned int secondsTen = 0;
volatile long unsigned int minutes = 0;

volatile long unsigned int lastSensorCheck = 0;
volatile long unsigned int lastLCDUpdate = 0;

/* Initialising various variables */
int sensorArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};   // Array to store sensor values for averaging
float adc_input = 0;                                    // ADC Input for IR Sensor
int distanceAway = 0;                                   // Distance in CM from IR Sensor

// ISR Space
ISR(TIMER2_OVF_vect)
{
  milliseconds++;       /* The Timer is set to overflow every millisecond. This variable will therefore increment every millisecond. */
  clockCount();
  if(milliseconds >= 1000)
  {
    milliseconds = 0;
    lastSensorCheck = 0;
    lastLCDUpdate = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  dataDirection(13,1);
  dataDirection(12,1);
  dataDirection(11,1);
  dataDirection(3,1);
  setupTimer();
  setupADC();
  lcd.begin(16, 2);
}

void loop() {
  // This code will read from an IR sensor 10 times, take the average, and print it to a 16x2 LCD screen
  int j;
    for(j=0;j<10;j++)
    {
      if(milliseconds - lastSensorCheck >= SENSOR_CHECK)
      {
        adc_input = sensorCheck();
        sensorArray[j] = adc_input;
        lastSensorCheck = milliseconds;
      }
    } 
    if(milliseconds - lastLCDUpdate >= LCD_UPDATE)
    {
      float adc_average = (sensorArray[0]+sensorArray[1]+sensorArray[2]+sensorArray[3]+sensorArray[4]+sensorArray[5]+sensorArray[6]+sensorArray[7]+sensorArray[8]+sensorArray[9])/10;
      float distanceVar = pow(adc_average, -1.075);
      distanceAway = 17285*distanceVar;
      lcd.setCursor(0,1);
      lcd.print(distanceAway);
      lcd.print(" ");
      lcd.print("cm");
      lastLCDUpdate = milliseconds;
    }  
    if(distanceAway < 100)
    {
      lcd.setCursor(5,1);
      lcd.print(" ");
    }
}

void dataDirection(int Pin, int OutIn)
{
  volatile uint8_t *port;
  if(Pin<=7)
  {
    port = &DDRD;
  }
  else if(Pin<=13)
  {
    port = &DDRB;
  }
  if(OutIn == 1 && Pin<=7)
  {
    *port|=(1<<Pin);
  }
  else if(OutIn == 1 && Pin<=13)
  {
    *port|=(1<<(Pin-8));
  }
  else if(OutIn == 0 && Pin<=7)
  {
    *port&=~(1<<Pin);
  }
  else if(OutIn == 0 && Pin<=13)
  {
    *port&=~(1<<(Pin-8));
  }
}

void setupTimer()
{
  TCCR2A = 0x00;                                         /* setting clock in normal mode */
  TCCR2B |= (1<<CS22);                                   /* setting up prescaler for 64 */
  TCCR2B &= ~((1<<CS21)|(1<<CS20));
  TCNT2 = 0;                                             /* Starting clock from 0. */
  
  TIMSK2 |= (1<<TOIE2);                                  /* Enabling Overflow Interrupt */
  sei();                                                 /* Enabling Global Interrupts */
  TIFR2 |= (1<<TOV2);                                    /* Clearing Overflow Interrupt Flag */
}

void setupADC()
{
   ADMUX = (1<<REFS0);                                         //<---- Setup ADC Multiplexer Selection Register, so that Vcc is the Ref, it should be "AVCC with external capacitor at AREF pin"
                                                               //<---- Setup ADC Multiplexer Selection Register, so that the result is right justified
   ADCSRA = (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);  //<---- Setup ADC Control and Status Register A, so that ADC is enabled, set up conversion rate to 125kHz. Remember Clock/Prescaler, you can select prescaler
}

/* This function will read the analog value being returned by the distance sensor */
/* Sensor Data Pin set to ADC1 on ATmega328P microchip */
int sensorCheck()
{
  ADMUX &= ~(0x00);              // Turn off ADC0 and turn on ADC1 only whenever required to take a distance reading
  ADMUX |= 0x01;
  ADCSRA |= (1<<ADSC);
  while(!(ADCSRA & 1<<ADIF));
  ADCSRA |= (1<<ADIF);
  return ADC;
}

/* This function will count up the digital clock when called */
void clockCount()
{
  if(milliseconds >= 1000)
    {
      secondsUnit++;
    }
  if(secondsUnit >= 10)
    {
      secondsTen++;
      secondsUnit = 0;
    }
  if(secondsTen >= 6)
    {
      minutes++;
      secondsTen = 0;
    }
}

