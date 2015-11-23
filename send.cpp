/*
Switch on/off usage : 
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
Hexa usage : 
 Usage: ./send <systemCode> <pulse> <bit>
 Bit must be different from 0, 1, and 2, so the program uses hexa instead of Switch On/off or binary
Binary usage : 
 Usage: ./send <systemCode> <pulse> 2
 Last argument must be set to 2 so the program uses binary instead of Switch On/off or hexa	
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */



    int PIN = 0;
    char* systemCode = argv[1];
    int unitCode = atoi(argv[2]);
    int command  = atoi(argv[3]);

     /*
     Added the possibility to send binaries, instead of switchOn/switchOff
     */
     int code = atoi(argv[1]);
     int pulse = atoi(argv[2]);
     int bit = atoi(argv[3]);

    
    if (wiringPiSetup () == -1) return 1;
	printf("sending systemCode[%s] unitCode[%i] command[%i]\n", systemCode, unitCode, command);
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);
    
    switch(command) {
        case 1:
            mySwitch.switchOn(systemCode, unitCode);
            break;
        case 0:
            mySwitch.switchOff(systemCode, unitCode);
            break;
	case 2:
             mySwitch.setPulseLength(pulse);
             mySwitch.send(systemCode);
            break;
	default:
             mySwitch.setPulseLength(pulse);
             mySwitch.send(code, bit);
            break;

    }
	return 0;
}
