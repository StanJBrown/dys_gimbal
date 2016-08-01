#include <serial/serial.h>
#include <string>
#include <stdio.h>
#include <inttypes.h>
#include <SBGC.h>

#define SERIAL_SPEED 115200
#define SBGC_CMD_DELAY 20


int main()
{
  std::string port_name = "/dev/ttyUSB0";
  int32_t baud = 115200;

  serial::Serial port;
  serial::Timeout to(serial::Timeout::simpleTimeout(500));
  port.setTimeout(to);
  port.setPort(port_name);
  port.setBaudrate(baud);

  port.open();

  if (port.isOpen()){
	  printf("SBGC port open");
  } else {
	  printf("SBGC Port not open");
  }

  SBGC_cmd_control_t c {0, 0, 0, 0, 0, 0, 0};
  SBGC_Parser sbgc_parser;
  sbgc_parser.init(&port);


  return 0;
}

