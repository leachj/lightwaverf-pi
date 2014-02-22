#include "LightwaveRF.h"
#include <stdlib.h>

byte on[] = {0xf6,0xf6,0xee,0xee,0x6f,0xed,0xbb,0xdb,0x7b,0xee};
byte off[] = {0xf6,0xf6,0xee,0xf6,0x6f,0xed,0xbb,0xdb,0x7b,0xee};


int main(int argc, char *argv[]) {

	lw_setup();

	//int unitCode = atoi(argv[1]);
    	int command  = atoi(argv[1]);
    
	printf("sending command[%i]\n", command);
    
    switch(command) {
        case 1:
            lw_send(on);
            break;
        case 0:
	    lw_send(off);
            break;
        default:
            printf("command[%i] is unsupported\n", command);
            return -1;
    }
	return 0;

}
