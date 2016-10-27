#include "lightwaverf.h"
#include <stdlib.h>

byte data[] = { 0xf6, // header - constant
                0xf6, // header - constant
                0xf6, // Unit number zero indexed, 0xf6 = 0, unit 1
                0xee, // command - 0xee for on 0xf6 for off, this can be dimmed using a value between 0x40 to 0x9f
                0x6f, // character 1 of ID
                0xed, // character 2 of ID
                0xbb, // character 3 of ID
                0xdb, // character 4 of ID
                0x7b, // character 5 of ID
                0xee  // character 6 of ID (last)
                };

byte lookup[] = {       0xf6, // 0  (0x0)
                        0xee, // 1  (0x1)
                        0xed, // 2  (0x2)
                        0xeb, // 3  (0x3)
                        0xde, // 4  (0x4)
                        0xdd, // 5  (0x5)
                        0xdb, // 6  (0x6)
                        0xbe, // 7  (0x7)
                        0xbd, // 8  (0x8)
                        0xbb, // 9  (0x9)
                        0xb7, // 10 (0xA)
                        0x7e, // 11 (0xB)
                        0x7d, // 12 (0xC)
                        0x7b, // 13 (0xD)
                        0x77, // 14 (0xE)
                        0x6f  // 15 (0xF)
                };

//this function should handle   ./send 1
// and                          ./send ID Unit On
// e.g                          ./send F3E029 2 1
int main(int argc, char *argv[]) //argc is the number of arguments passed in, ./send 1 will be 2. argv[] is an array of arguments
{
        lw_setup();

        //int unitCode = atoi(argv[1]);
        int command  = atoi(argv[1]);
        char id[] = "f296d1";
        int unit = 2;

        if (argc == 4)
        {
                strcpy(id, argv[1]); // set id to arg 1
                unit = atoi(argv[2]); //set the unit number
                command = atoi(argv[3]); // set the command on/off
        }
        else if (argc == 2)
        {
                // all is fine and dandy
        }
        else
        {
                printf("Arguments are not correct");
                return -1;
        }

        byte message[10];
        memcpy(message, data, 10);// we want to keep the original data for users that

        int i = 0;
        while( i < 6) //cycles through the id characters and corrects the message using the lookup table
        {
                char idChar = id[i]; // gets the current character of the ID
                char singleChar[2] = {idChar, 0}; // convert to a string by creating a char array and adding null terminator /0
                int lookupIndex = (int)strtol(singleChar, NULL, 16); // bluh, looks a horrible piece of code. It basically takes a hex character converts to an int.
                message[i + 4] = lookup[lookupIndex]; //change our message
                i++; //increment counter
        }


        message[2] = lookup[unit-1]; // write which unit we require to the message. we minus one as the unit is zero based index
        message[3] = lookup[command]; // convert the command  and put into the message
        printf("sending command[%i] to ID:[%s] \n", command, id);

        lw_send(message);
        return 0;

}

