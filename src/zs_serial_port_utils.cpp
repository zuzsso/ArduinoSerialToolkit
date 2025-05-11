#include <Arduino.h>
#include <zs_serial_port_utils.h>

namespace ZS
{
   namespace SerialPort
   {
      void runtimeException(String s)
      {
         Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
         Serial.println("!!! RTE: " + s);
         while (true)
         {
            // Yes, infinite loop. The other option would be tor
            // throw a runtime exception, but that would cause
            // the MCU to restart continuously
         }
      }
      void setupSerialPort(unsigned long baudRate)
      {
         Serial.begin(baudRate);
         Serial.setDebugOutput(true);
      }

      void writeMessageToSerialPort(String s)
      {
         Serial.println(s);
      }

      void writeErrorToSerialPort(String s)
      {
         Serial.println(">>> ERR: " + s);
      }

      void writeDebugLineToSerialPort(String s)
      {
         Serial.println("------------------------");
         Serial.println("    DEBUG: " + s);
      }

      String readLine()
      {
         String input = "";
         while (true)
         {
            while (Serial.available() > 0)
            {
               char c = Serial.read();
               if (c == '\n')
               {
                  return input;
               }
               else if (c != '\r')
               {
                  input += c;
               }
            }
         }
      }
   }
}
