/* Jillian Coveney
 * COEN 146L: Lab2 step 3
 * Thursday 5:15
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
        if (argc != 2) {  // check correct usage
		fprintf(stderr, "usage: %s <n connections> \n", argv[0]);
		exit(1);
	}
       //Declare and values to n (n connections), np (np parralel connections), RTT0, RTT1, RTT2, RTTHTTP, RTTDNS, .. 
        int n = atoi(argv[1]);	//n parallel connections
	
	int RTT0 = 3;
	int RTT1 = 20;	
	int RTT2 = 26;
	int RTTDNS = RTT0 + RTT1 + RTT2;
	int RTTHTTP = 47;

      	int a = RTTDNS + 2*RTTHTTP; 
        printf("One object: %d msec\n", a);
	
	int b = RTTDNS + 2*RTTHTTP + 2*6*RTTHTTP;
        printf("Non-Persistent 6 objects: %d msec\n", b);

        //find how many np (parralel connections)
        int np = (n>6)? 1: 6/n;
	if((n<6) && (6%n != 0)){
		np += 1;
	}
        int c_i = RTTDNS + 2*RTTHTTP + np*RTTHTTP;
        printf("%d parallel connection - Persistent: %d msec\n", n, c_i);

	int c_ii = RTTDNS + 2*RTTHTTP + 2*np*RTTHTTP;
        printf("%d parallel connection - Non-Persistent: %d msec\n", n, c_ii);

return 0;
}
