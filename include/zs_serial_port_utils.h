#include <Arduino.h>

#ifndef __ZS_SERIAL_PORT_TOOLKIT__
#define __ZS_SERIAL_PORT_TOOLKIT__

namespace ZS
{
   namespace SerialPort
   {
      void runtimeException(String s);
      void setupSerialPort(unsigned long baudRate);
      void writeMessageToSerialPort(String s);
      void writeErrorToSerialPort(String s);
      void writeDebugLineToSerialPort(String s);
      String readLine();
   }
}

#endif
