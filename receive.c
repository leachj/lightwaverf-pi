#include "lightwaverf.h"
#include <stdlib.h>


void printMsg(byte *msg, byte len) {
  int i;
  for(i=0;i<len;i++) {
    printf("%02X ",msg[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {

	lw_setup();

	while(1){

		byte msg[10];
  		byte len = 10;

  		lw_rx_wait();
  		lw_get_message(msg,&len);
  		printMsg(msg, len);
	}

	return 0;

}
