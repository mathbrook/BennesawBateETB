/*********************

Example code for the Adafruit RGB Character LCD Shield and Library

This code displays text on the shield, and also reads the buttons on the keypad.
When a button is pressed, the backlight changes color.

**********************/

// include the library code:
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#include <Servo.h>



// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
Servo etb_servo;
int etbPosition = 0; //variable that contains the degrees
//
// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7
//State var define
uint8_t state=0;
void etb_state_machine(uint8_t etb_state);
void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  etb_servo.attach(3);
  // Print a message to the LCD. We track how long it takes since
  // this library has been optimized a bit and we're proud of it :)
  int time = millis();
  lcd.print("Hello, world!");
  time = millis() - time;
  Serial.print("Took "); Serial.print(time); Serial.println(" ms");
  lcd.setBacklight(WHITE);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(etbPosition);

  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_UP) {
      lcd.print("+1 deg.");
      lcd.setBacklight(RED);
      etbPosition++;
      etb_servo.write(etbPosition);
    }
    if (buttons & BUTTON_DOWN) {
      lcd.print("-1 deg.");
      lcd.setBacklight(RED);
      etbPosition--;
      etb_servo.write(etbPosition);
    }
    if (buttons & BUTTON_LEFT) {
      lcd.print("Wide Open ");
      lcd.setBacklight(GREEN);
      etbPosition=90;
      etb_servo.write(etbPosition);
    }
    if (buttons & BUTTON_RIGHT) {
      lcd.print("Closed or Idle ");
      lcd.setBacklight(TEAL);
      etbPosition=0;
      etb_servo.write(etbPosition);

    }
    if (buttons & BUTTON_SELECT) {
      lcd.print("SELECT ");
      lcd.setBacklight(VIOLET);
    }
  }
}
void etb_state_machine(uint8_t etb_state){
  switch (etb_state)  {
    case 0:{

    }
    case 1:{

    }
    case 2:{

    }
    case 3:{

    }
  }
}