/*
 * File:        bincount.c
 *
 * Description: This file contains the main function for testing a set
 *              abstract data type for strings.
 *
 *              The program takes a single file as a command line argument.
 *              An array of sets is used to count the number of words of
 *              varying lengths.  The counts of the number of distinct
 *              words of each length are printed.
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "set.h"


/* This is sufficient for the test cases in /scratch/coen12. */

# define MAX_UNIQUE 18000
# define NUM_BINS 20


/*
 * Function:    main
 *
 * Description: Driver function for the test application.
 */

int main(int argc, char *argv[])
{
    FILE *fp;
    char buffer[BUFSIZ];
    SET *sets[NUM_BINS];
    int i;


    /* Check usage and open the file. */

    if (argc != 2) {
        fprintf(stderr, "usage: %s file1\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s: cannot open %s\n", argv[0], argv[1]);
        exit(EXIT_FAILURE);
    }


    /* Insert all words into the set of the appropriate length. */

    for (i = 0; i < NUM_BINS; i ++)
	sets[i] = createSet(MAX_UNIQUE);

    while (fscanf(fp, "%s", buffer) == 1)
	if (strlen(buffer) <= NUM_BINS)
	    addElement(sets[strlen(buffer) - 1], buffer);

    fclose(fp);


    /* Display the counts for each word length. */

    for (i = 0; i < NUM_BINS; i ++) {
	printf("%5d distinct words ", numElements(sets[i]));
	printf("of length %d\n", i + 1);
    }

    exit(EXIT_SUCCESS);
}
