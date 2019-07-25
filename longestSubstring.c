/*
 * Given a string, find the length of the longest substring without repeating characters.
 * Example inputs and outputs:
 * abcabcbb = 3
 * bbbbb = 1
 * pwwkew = 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_ARGS -1
#define OK 0

#ifdef __DEBUG__
#define CONSOLE(x) printf x
#else
#define CONSOLE(x) do {} while (0)
#endif

typedef enum {false, true} BOOLEAN;

int main (int argc, char **argv) {

	if (argc < 2) {
		CONSOLE(("No arguments\n"));
		exit(NO_ARGS);
	}

	BOOLEAN bitmap[255];
	for (unsigned i = 0 ; i <= 255 ; i++) {
		bitmap[i] = false;
	}

	CONSOLE(("Input: %s\n",argv[1]));
	char position;
	unsigned count = 0;
	unsigned aux = 0;
	for (unsigned i = 0 ; i < strlen(argv[1]) ; i++) {
		position = argv[1][i];

		if (bitmap[position] == true) {
			for (unsigned j = 0 ; j <= 255 ; j++) {
				bitmap[j] = false;
        	}
		
			if (count > aux) {	
				aux = count;
				CONSOLE(("Aux received the value of %u from count\n",count));
			}

			count = 0;
		}

		bitmap[position] = true;
		CONSOLE(("Mapped position %u as true\n", position));
		
		count++;
		CONSOLE(("Counter is %u\n", count));
	}

	if (count > aux) {
		aux = count;
	}

	printf("Size of substring: %u\n", aux);

	return OK;
}

