
/**
    * Simple import test from stdin for MongoDB.
    *
    * Create a high number of simple JSON lines within 1 second and pipe to the mongoimport command.
    * JSON lines circumvent the current Mongo import limit of 4MB for a JSON array.
    *
    * Compile:
    *                 GCC: gcc mongobench.c -o mb[.exe] -O3 -Wall -s
    *                 TCC: mongobench.c mb[.exe]
    *
    * Usage:
    *                 mb[.exe] | mongoimport --db junk --collection years --drop
    *
    * Output:
    *                 Windows:   imported 140416 documents
    *
    *                 Linux:     89900      29966/second
    *                            210900     35150/second
    *                            ...
    *                            Ctrl + C   quit
    *
    * @author         Martin Latter, <copysense.co.uk>
    * @copyright      Martin Latter, 24/07/2015
    * @version        0.2
    * @license        GNU GPL version 3.0 (GPL v3); http://www.gnu.org/licenses/gpl.html
    * @link           https://github.com/Tinram/Mongo-Bench.git
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STRLEN 10
#define YEARS 2000


int main() {

	srand(time(NULL));

	int iMSec = 0;
	int iYear;
	int i;
		// int iCount = 0;
	char aEvent[STRLEN + 1];
	char aEvent2[STRLEN + 1];
	clock_t tStart, tDiff;

	tStart = clock();

	do {

		iYear = (rand() % YEARS);

		for (i = -1; ++i < STRLEN;) {
			aEvent[i] = (rand() % 26) + 65; // uppercase
			aEvent2[i] = (rand() % 26) + 97; // lowercase
		}

		aEvent[STRLEN] = '\0';
		aEvent2[STRLEN] = '\0';

		printf("{year:%d,events:[{e1:'%s'},{e2:'%s'}]}\n", iYear, aEvent, aEvent2); // JSON output

			// printf("{'year':'%d'}\n", iYear); // alternative: simplest JSON schema
			// iCount++;

		tDiff = clock() - tStart;
		iMSec = tDiff * 1000 / CLOCKS_PER_SEC;

	} while ((iMSec * 0.001) < 1);

		/* uncomment the following two lines (and the iCount-related lines above), compile, and redirect to a text file, and tail: see how many lines the program will print to file in 1 second */
		// printf("time: %d s %d ms\n", iMSec / 1000, iMSec % 1000);
		// printf("count: %d \n", iCount);

	return 0;
}
