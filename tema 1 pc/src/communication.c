#include "communication.h"
#include "util_comm.h"
#include <string.h>
#include <stdio.h>


/* Task 1 - The Beginning */

void send_byte_message(void)
{
    /* TODO
     * Send the encoding of the characters: R, I, C, K
     */
    send_squanch(18);
    send_squanch(9);
    send_squanch(3);
    send_squanch(11);
}


void recv_byte_message(void)
{
    /* TODO
     * Receive 5 encoded characters, decode them and print
     * them to the standard output (as characters)
     *
     * ATTENTION!: Use fprintf(stdout, ...)
     */
    uint8_t primim_caracter[1000];
    for (int i = 0; i < 5; i++) {
        primim_caracter[i] = recv_squanch();
        if (primim_caracter[i] == 1)
            fprintf(stdout, "%s", "A");
        if (primim_caracter[i] == 2)
            fprintf(stdout, "%s", "B");
        if (primim_caracter[i] == 3)
            fprintf(stdout, "%s", "C");
        if (primim_caracter[i] == 4)
            fprintf(stdout, "%s", "D");
        if (primim_caracter[i] == 5)
            fprintf(stdout, "%s", "E");
        if (primim_caracter[i] == 6)
            fprintf(stdout, "%s", "F");
        if (primim_caracter[i] == 7)
            fprintf(stdout, "%s", "G");
        if (primim_caracter[i] == 8)
            fprintf(stdout, "%s", "H");
        if (primim_caracter[i] == 9)
            fprintf(stdout, "%s", "I");
        if (primim_caracter[i] == 10)
            fprintf(stdout, "%s", "J");
        if (primim_caracter[i] == 11)
            fprintf(stdout, "%s", "K");
        if (primim_caracter[i] == 12)
            fprintf(stdout, "%s", "L");
        if (primim_caracter[i] == 13)
            fprintf(stdout, "%s", "M");
        if (primim_caracter[i] == 14)
            fprintf(stdout, "%s", "N");
        if (primim_caracter[i] == 15)
            fprintf(stdout, "%s", "O");
        if (primim_caracter[i] == 16)
            fprintf(stdout, "%s", "P");
        if (primim_caracter[i] == 17)
            fprintf(stdout, "%s", "Q");
        if (primim_caracter[i] == 18)
            fprintf(stdout, "%s", "R");
        if (primim_caracter[i] == 19)
            fprintf(stdout, "%s", "S");
        if (primim_caracter[i] == 20)
            fprintf(stdout, "%s", "T");
        if (primim_caracter[i] == 21)
            fprintf(stdout, "%s", "U");
        if (primim_caracter[i] == 22)
            fprintf(stdout, "%s", "V");
        if (primim_caracter[i] == 23)
            fprintf(stdout, "%s", "W'");
        if (primim_caracter[i] == 24)
            fprintf(stdout, "%s", "X");
        if (primim_caracter[i] == 25)
            fprintf(stdout, "%s", "Y");
        if (primim_caracter[i] == 26)
            fprintf(stdout, "%s", "Z");
    }

}

void comm_byte(void)
{
    /* TODO
     * Receive 10 encoded characters and send each character (the character is
     * still encoded) 2 times
     */
    //dc caracterul primit este numar - adica in forma
    //codificata, atunci voi trimite caractrerul de doua
    //ori inapoi, altfel trec mai departe si verific
    uint8_t recive_ten_char[10];
    for (int i = 0; i < 10; i++) {
        recive_ten_char[i] = recv_squanch();
        uint8_t a = recive_ten_char[i];
        if(a == 1){
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 2) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 3) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 4) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 5) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 6) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 7) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 8) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 9) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 10) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 11) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 12) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 13) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 14) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 15) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 16) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 17) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 18) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 19) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 20) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 21) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 22) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 23) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 24) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 25) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }
        if (a == 26) {
            for (int i = 0; i < 2; i++) {
                send_squanch(a);
            }
        }

    }
}


/* Task 2 - Waiting for the Message */

void send_message(void)
{
    /* TODO
     * Send the message: HELLOTHERE
     * - send the encoded length
     * - send each character encoded
     */
    
    send_squanch(40);//00xxxx00
    send_squanch(8);
    send_squanch(5);
    send_squanch(12);
    send_squanch(12);
    send_squanch(15);
    send_squanch(20);
    send_squanch(8);
    send_squanch(5);
    send_squanch(18);
    send_squanch(5);
  
    
}


void recv_message(void)
{
    /* TODO
     * Receive a message:
     * - the first value is the encoded length
     * - length x encoded characters
     * - print each decoded character
     * 
     * ATTENTION!: Use fprintf(stdout, ...)
     */


    uint8_t n = recv_squanch();

    uint8_t nr = n << 2;

    nr = nr >> 4;

    fprintf(stdout, "%d", nr);
   
    for (int i = 0; i < nr; i++) {
        uint8_t primesc = recv_squanch();       
        fprintf(stdout, "%c", primesc + 64);
    }
}


void comm_message(void)
{
    /* TODO
     * Receive a message from Rick and do one of the following depending on the
     * last character from the message:
     * - 'P' - send back PICKLERICK
     * - anything else - send back VINDICATORS
     * You need to send the messages as you did at the previous tasks:
     * - encode the length and send it
     * - encode each character and send them
     */

    uint8_t lungime;
    uint8_t caracter_primit[100];

    lungime = recv_squanch();

    uint8_t nr = lungime << 2;
    nr = nr >> 4;

    //fprintf(stdout, "%d", nr);

    for (int i = 0; i < nr; i++) {
        caracter_primit[i] = recv_squanch();
        }

    if (caracter_primit[nr-1] ==  16) {
        send_squanch(40);
        send_squanch(16);
        send_squanch(9);
        send_squanch(3);
        send_squanch(11);
        send_squanch(12);
        send_squanch(5);
        send_squanch(18);
        send_squanch(9);
        send_squanch(3);
        send_squanch(11);
    }
    else {
        send_squanch(44);
        send_squanch(22);
        send_squanch(9);
        send_squanch(14);
        send_squanch(4);
        send_squanch(9);
        send_squanch(3);
        send_squanch(1);
        send_squanch(20);
        send_squanch(15);
        send_squanch(18);
        send_squanch(19);
    }

    

}


/* Task 3 - In the Zone */

void send_squanch2(uint8_t c1, uint8_t c2)
{
    /* TODO
     * Steps:
     * - "merge" the character encoded in c1 and the character encoded in c2
     * - use send_squanch to send the newly formed byte
     */
    uint8_t merge ;//unde imbinam
    //merge = (((c1 >> 3)) << 7) + ((c2 >> 3) << 6) + (((c1 >> 2) << 7) >> 2) +
    //(((c2 >> 2) << 7) >> 3) + (((c1 >> 1) << 7) >> 4) + 
    //(((c2 >> 1) << 7) >> 5) + (((c1 << 7))>>6) + ((c2 << 7) >> 7);
    
    uint8_t ac1 = (((c1 >> 3)) << 7);
    uint8_t ac2 = ((c2 >> 3) << 6);

    uint8_t ajut_bc1 = ((c1 >> 2) << 7) ;
    uint8_t bc1 = ajut_bc1 >> 2;

    uint8_t ajut_bc2 = ((c2 >> 2) << 7);
    uint8_t bc2 = ajut_bc2 >> 3;

    uint8_t ajut_cc1 = ((c1 >> 1) << 7);
    uint8_t cc1 = ajut_cc1 >> 4;

    uint8_t ajut_cc2 = ((c2 >> 1) << 7);
    uint8_t cc2 = ajut_cc2 >> 5;

    uint8_t ajut_dc1 =c1 << 7;
    uint8_t dc1 = ajut_dc1 >> 6;

    uint8_t ajut_dc2 = c2 << 7;
    uint8_t dc2 = ajut_dc2 >> 7;

    merge = ac1 + ac2 + bc1 + bc2 + cc1 + cc2 + dc1 + dc2;

    //merge = ajut_dc2;
    send_squanch(merge);
}


uint8_t decode_squanch2(uint8_t c)
{
    /*
     * Decode the given byte:
     * - split the two characters as in the image from ocw.cs.pub.ro
     */

    uint8_t res = -1;

    uint8_t ac1 = ((c >> 7) << 7);

    uint8_t ajut_ac2 = ((c >> 6) << 7);
    uint8_t ac2 = ajut_ac2 >> 1;

    uint8_t ajut_bc1 = ((c >> 5) << 7);
    uint8_t bc1 = ajut_bc1 >> 2;

    uint8_t ajut_bc2 = ((c >> 4) << 7);
    uint8_t bc2 = ajut_bc2 >> 3;

    uint8_t ajut_cc1 = ((c >> 3) << 7);
    uint8_t cc1 = ajut_cc1 >> 4;

    uint8_t ajut_cc2 = ((c >> 2) << 7);
    uint8_t cc2 = ajut_cc2 >> 5;

    uint8_t ajut_dc1 = ((c >> 1)<<7);
    uint8_t dc1 = ajut_dc1 >> 6;

    uint8_t ajut_dc2 = c << 7;
    uint8_t dc2 = ajut_dc2 >> 7;

    //ac2 = ac2 >> 1;
    bc1 = bc1 << 1;
    cc1 = cc1 << 2;
    dc1 = dc1 << 3;

    bc2 = bc2 >> 2;
    cc2 = cc2 >> 1;
    ac2 = ac2 >> 3;



    /* TODO */
    res = ac1 + ac2 + bc1 + bc2 + cc1 + cc2 + dc1 + dc2;
    return res;
}
