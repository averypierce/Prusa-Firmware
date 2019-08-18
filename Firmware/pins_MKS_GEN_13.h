/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Arduino Mega with RAMPS v1.4 adjusted pin assignments
 *
 *  MKS GEN v1.3  (Extruder, Fan, Bed)
 *  MKS GEN v1.3  (Extruder, Extruder, Fan, Bed)
 *  MKS GEN v1.4  (Extruder, Fan, Bed)
 *  MKS GEN v1.4  (Extruder, Extruder, Fan, Bed)
 */
#define ELECTRONICS "hotdog"
#define KNOWN_BOARD

#define BEEPER              37  // Beeper on AUX-4
#define LCD_PINS_RS         16
#define LCD_PINS_ENABLE     17
#define LCD_PINS_D4	        23
#define LCD_PINS_D5         25
#define LCD_PINS_D6         27
#define LCD_PINS_D7         29


#define Z_TMC2130_CS        42
#define Z_TMC2130_DIAG      65

#define E0_TMC2130_CS       44
#define E0_TMC2130_DIAG     66

#define X_TMC2130_CS       40
#define X_TMC2130_DIAG     63

#define Y_TMC2130_CS       59
#define Y_TMC2130_DIAG     64


#define BTN_ENC             35
#define SDCARDDETECT        49
#define SDPOWER             -1
#define BTN_EN1             31
#define BTN_EN2             33

#define TEMP_AMBIENT_PIN     5 //A6
#define TEMP_PINDA_PIN       3 //A1
#define TEMP_2_PIN          -1

#define IR_SENSOR_PIN       62 //A8
#define FAN_PIN              6 
#define FAN_1_PIN           -1 
#define TACH_0				      30	// noctua extruder fan

#define AMBIENT_THERMISTOR
#define PINDA_THERMISTOR

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS GEN 1.3/1.4 supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_NAME "MKS GEN >= v1.3"

//
// Heaters / Fans
//
// Power outputs EFBF or EFBE
#define MOSFET_D_PIN 7

//
// PSU / SERVO
//
// If POWER_SUPPLY is specified, always hijack Servo 3
//
#if POWER_SUPPLY > 0
  #define SERVO3_PIN      -1
  #define PS_ON_PIN        4
#endif

#include "pins_RAMPS.h"

//
// LCD / Controller
//
#if ENABLED(VIKI2) || ENABLED(miniVIKI)
  /**
   * VIKI2 Has two groups of wires with...
   *
   * +Vin     + Input supply, requires 120ma for LCD and mSD card
   * GND      Ground Pin
   * MOSI     Data input for LCD and SD
   * MISO     Data output for SD
   * SCK      Clock for LCD and SD
   * AO       Reg. Sel for LCD
   * LCS      Chip Select for LCD
   * SDCS     Chip Select for SD
   * SDCD     Card Detect pin for SD
   * ENCA     Encoder output A
   * ENCB     Encoder output B
   * ENCBTN   Encoder button switch
   *
   * BTN      Panel mounted button switch
   * BUZZER   Piezo buzzer
   * BLUE-LED Blue LED ring pin (3 to 5v, mosfet buffered)
   * RED-LED  Red LED ring pin (3 to 5v, mosfet buffered)
   *
   * This configuration uses the following arrangement:
   *
   * EXP1 D37 = EN2   D35 = EN1     EXP2 D50 = MISO  D52 = SCK
   *      D17 = BLUE  D16 = RED          D31 = ENC   D53 = SDCS
   *      D23 = KILL  D25 = BUZZ         D33 = ---   D51 = MOSI
   *      D27 = A0    D29 = LCS          D49 = SDCD  RST = ---
   *      GND = GND   5V  = 5V           GND = ---   D41 = ---
   */

  #undef BTN_EN1
  #undef BTN_EN2
  #undef BTN_ENC
  #undef DOGLCD_A0
  #undef DOGLCD_CS
  #undef SD_DETECT_PIN
  #undef BEEPER_PIN
  #undef KILL_PIN

  //
  // VIKI2 12-wire lead
  //

  // orange/white         SDCD
  #define SD_DETECT_PIN   49

  // white                ENCA
  #define BTN_EN1         35

  // green                ENCB
  #define BTN_EN2         37

  // purple               ENCBTN
  #define BTN_ENC         31

  // brown                A0
  #define DOGLCD_A0       27

  // green/white          LCS
  #define DOGLCD_CS       29

                       // 50    gray   MISO
                       // 51    yellow MOSI
                       // 52    orange SCK

  // blue                 SDCS
  //#define SDSS            53

  //
  // VIKI2 4-wire lead
  //

  // blue                 BTN
  #define KILL_PIN        23

  // green                BUZZER
  #define BEEPER_PIN      25

  // yellow               RED-LED
  #define STAT_LED_RED_PIN 16

  // white                BLUE-LED
  #define STAT_LED_BLUE_PIN 17

#endif
