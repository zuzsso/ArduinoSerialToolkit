#include <Arduino.h> 

#ifndef __ARDUINO_SERIAL_PORT_TOOLKIT__
#define __ARDUINO_SERIAL_PORT_TOOLKIT__
namespace Arduino{
   namespace SerialPort {
      void runtimeException(String s) {
         Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
         Serial.println("!!! RTE: " + s);         
         while (true){
        // Yes, infinite loop.
         } 
             
      }
      void setupSerialPort(unsigned long baudRate) {
         Serial.begin(baudRate);
         Serial.setDebugOutput(true);
      }

      void writeMessageToSerialPort(String s) {
         Serial.println(s);
      }

      void writeErrorToSerialPort(String s) {
         Serial.println(">>> ERR: " + s);
      }

      void writeDebugLineToSerialPort(String s) {
         Serial.println("------------------------");
         Serial.println("    DEBUG: " + s);
      }

      String readLine() {
         String input = "";
         while (true) {
            while (Serial.available() > 0) {
               char c = Serial.read();
               if (c == '\n') {
                  return input;
               } else if (c != '\r') {
                  input += c;
               }
            }
         }
      }
   }
} 
#endif
