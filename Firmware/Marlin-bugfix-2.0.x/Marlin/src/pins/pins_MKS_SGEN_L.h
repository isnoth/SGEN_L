/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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
 * MKS SBASE pin assignments
 */

#ifndef TARGET_LPC1768
  #error "Oops! Make sure you have the LPC1768 environment selected in your IDE."
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME        "MKS SGEN_L"
#endif
#ifndef BOARD_WEBSITE_URL
  #define BOARD_WEBSITE_URL "https://github.com/makerbase-mks/MKS-SGEN_L"
#endif

#define LED_PIN            P1_18   // Used as a status indicator
#define LED2_PIN           P1_19
#define LED3_PIN           P1_20
#define LED4_PIN           P1_21

//
// Servo pin
//
#define SERVO0_PIN         P1_23   // SERVO P1.23
#define SERVO1_PIN         P2_00   // SERVO P2.0

//
// Limit Switches
//
#define X_MIN_PIN          P1_29
#define X_MAX_PIN          P1_28
#define Y_MIN_PIN          P1_27
#define Y_MAX_PIN          P1_26
#define Z_MIN_PIN          P1_25
#define Z_MAX_PIN          P1_24

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  P1_24
#endif

//
// Steppers
//
#define X_STEP_PIN         P2_02
#define X_DIR_PIN          P2_03
#define X_ENABLE_PIN       P2_01
#ifndef X_CS_PIN
  #define X_CS_PIN         P1_01
#endif

#define Y_STEP_PIN         P0_19
#define Y_DIR_PIN          P0_20
#define Y_ENABLE_PIN       P2_08
#ifndef Y_CS_PIN
  #define Y_CS_PIN         P1_08
#endif

#define Z_STEP_PIN         P0_22
#define Z_DIR_PIN          P2_11
#define Z_ENABLE_PIN       P0_21
#ifndef Z_CS_PIN
  #define Z_CS_PIN         P1_10
#endif

#define E0_STEP_PIN        P2_13
#define E0_DIR_PIN         P0_11
#define E0_ENABLE_PIN      P2_12
#ifndef E0_CS_PIN
  #define E0_CS_PIN         P1_15
#endif

#define E1_STEP_PIN        P0_01
#define E1_DIR_PIN         P0_00
#define E1_ENABLE_PIN      P0_10
#ifndef E1_CS_PIN
  #define E1_CS_PIN        P1_17
#endif


/**
 * Example for trinamic drivers using the J8 connector on MKs Sbase.
 * 2130s need 1 pin for each driver. 2208s need 2 pins for serial control.
 * This board does not have enough pins to use hardware serial.
 */

#if HAS_DRIVER(TMC2130)
  #define X_CS_PIN         P1_01
  #define Y_CS_PIN         P1_08
  #define Z_CS_PIN         P1_10
  #define E0_CS_PIN        P1_15
  #define E1_CS_PIN        P1_17

  #define TMC_SW_MOSI      P4_28
  #define TMC_SW_MISO      P0_05
  #define TMC_SW_SCK       P0_04

// https://github.com/makerbase-mks/MKS-SGEN_L
#define TMC_USE_SW_SPI
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI    P4_28
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO    P0_05
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK     P0_04
  #endif
 #endif
#endif

#if MB(MKS_SGEN_L) && HAS_DRIVER(TMC2208)
  /**
 * TMC2208 stepper drivers
 *
 * Hardware serial communication ports.
 * If undefined software serial is used according to the pins below
 */
//#define X_HARDWARE_SERIAL  Serial
//#define X2_HARDWARE_SERIAL Serial1
//#define Y_HARDWARE_SERIAL  Serial1
//#define Y2_HARDWARE_SERIAL Serial1
//#define Z_HARDWARE_SERIAL  Serial1
//#define Z2_HARDWARE_SERIAL Serial1
//#define E0_HARDWARE_SERIAL Serial1
//#define E1_HARDWARE_SERIAL Serial1
//#define E2_HARDWARE_SERIAL Serial1
//#define E3_HARDWARE_SERIAL Serial1
//#define E4_HARDWARE_SERIAL Serial1

//
// Software serial
//

#define X_SERIAL_TX_PIN  P1_04
#define X_SERIAL_RX_PIN  P1_01

#define Y_SERIAL_TX_PIN  P1_09
#define Y_SERIAL_RX_PIN  P1_08

#define Z_SERIAL_TX_PIN  P1_14
#define Z_SERIAL_RX_PIN  P1_10

#define E0_SERIAL_TX_PIN P1_16
#define E0_SERIAL_RX_PIN P1_15

#define E1_SERIAL_TX_PIN P4_29
#define E1_SERIAL_RX_PIN P1_17

#define Z2_SERIAL_TX_PIN P4_29
#define Z2_SERIAL_RX_PIN P1_17

#endif


//
// Temperature Sensors
// 3.3V max when defined as an analog input
//
#define TEMP_0_PIN         0   // A0 (TH1)
#define TEMP_BED_PIN       1   // A1 (TB)
#define TEMP_1_PIN         2   // A2 (TH2)
#define TEMP_2_PIN         3   // A3 (P0.26)  TEST-POINT

//
// Heaters / Fans
//
#define HEATER_BED_PIN     P2_05
#define HEATER_0_PIN       P2_07
#define HEATER_1_PIN       P2_06
#ifndef FAN_PIN
  #define FAN_PIN          P2_04
#endif

//
// Misc. Functions
//
#define PS_ON_PIN          P1_23   // SERVO P1.23

/*
|               _____                                          _____
| (BEEPER)1.31 | · · | 1.30(BTN_ENC)             (SD_MISO)0.8 | · · | 0.7(SD_SCK)
| (LCD_EN)0.18 | · · | 0.16(LCD_RS)             (BTN_EN1)3.25 | · · | 0.28(SD_CS2)
| (LCD_D4)0.15 | · ·|  0.17(LCD_D5)             (BTN_EN2)3.26 | · ·|  1.20(SD_MOSI)
| (LCD_D6)1.0  | · · | 1.22(LCD_D7)           (SD_DETECT)0.27 | · · | RST
|          GND | · · | 5V                                 GND | · · | NC
|               ￣￣                                           ￣￣
|               EXP1                                            EXP2
*/

#if ENABLED(ULTRA_LCD)
  #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
	  #define BEEPER_PIN       P1_31
	  #define BTN_ENC          P1_30
	  #define BTN_EN1          P3_25
	  #define BTN_EN2          P3_26
	  #define LCD_PINS_RS      P0_16
	  #define LCD_SDSS         P0_28
	  #define LCD_PINS_ENABLE  P0_18
	  #define LCD_PINS_D4      P0_15

  #elif ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
  	#define BEEPER_PIN       P1_31
	  #define BTN_ENC          P1_30
	  #define BTN_EN1          P3_25
	  #define BTN_EN2          P3_26
	  #define LCD_PINS_RS      P0_16
	  #define LCD_SDSS         P0_28
	  #define LCD_PINS_ENABLE  P0_18
	  #define LCD_PINS_D4      P0_15
	  #define LCD_PINS_D5      P0_17
	  #define LCD_PINS_D6      P1_00
	  #define LCD_PINS_D7      P1_22
  #elif ENABLED(MKS_MINI_12864)
	  #define BEEPER_PIN       P1_31
	  #define BTN_ENC          P1_30
	  #define BTN_EN1          P3_25
	  #define BTN_EN2          P3_26
    #define DOGLCD_CS        P0_17
    #define DOGLCD_A0        P1_00
    #define DOGLCD_SCK       P0_07
    #define DOGLCD_MOSI      P0_09
    // Uncomment screen orientation
    //#define LCD_SCREEN_ROT_90
    //#define LCD_SCREEN_ROT_180
    //#define LCD_SCREEN_ROT_270
    #endif
#endif

#if !ANY(LPC_SD_LCD, LPC_SD_ONBOARD, LPC_SD_CUSTOM_CABLE)
  #undef USB_SD_DISABLED
  #define USB_SD_ONBOARD
  #define LPC_SD_ONBOARD
#endif


#if ENABLED(LPC_SD_LCD)
  // use standard cable and header, SPI and SD detect sre shared with on-board SD card
  // hardware SPI is used for both SD cards. The detect pin is shred between the
  // LCD and onboard SD readers so we disable it.
  #define SCK_PIN          P0_07
  #define MISO_PIN         P0_08
  #define MOSI_PIN         P0_09
  #define SS_PIN           P0_28   // Chip select for SD card used by Marlin
  #define ONBOARD_SD_CS    P0_06   // Chip select for "System" SD card

#elif ENABLED(LPC_SD_ONBOARD)

  // The external SD card is not used. Hardware SPI is used to access the card.
  #if ENABLED(USB_SD_ONBOARD)
    // When sharing the SD card with a PC we want the menu options to
    // mount/unmount the card and refresh it. So we disable card detect.
    #define SHARED_SD_CARD
  #else
    #define SD_DETECT_PIN  P0_27
  #endif
  #define SCK_PIN          P0_07
  #define MISO_PIN         P0_08
  #define MOSI_PIN         P0_09
  #define SS_PIN           P0_06   // Chip select for SD card used by Marlin
  #define ONBOARD_SD_CS    P0_06   // Chip select for "System" SD card

#endif

// UNUSED
#define PIN_P0_27          P0_27   // EXP2/Onboard SD
#define PIN_P0_28          P0_28   // EXP2
#define PIN_P0_02          P0_02   // AUX1 (Interrupt Capable/ADC/Serial Port 0)
#define PIN_P0_03          P0_03   // AUX1 (Interrupt Capable/ADC/Serial Port 0)
