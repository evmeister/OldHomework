/*
 * File:	vradix.c
 *
 * Description:	Generate a random array of integers and sort them using
 *		radix sort.  Each integer in the array is dropped into a
 *		bucket by its least significant digit.  After all integers
 *		are placed in buckets, the buckets are copied back into the
 *		original array and we repeat the process, but with the next
 *		most significant digit.  After all digits have been
 *		processed, the array is sorted!  Since the buckets need to
 *		preserve the order of insertion, we need to implement a
 *		queue.  A deque provides this functionality for us.  The
 *		algorithm can be found at wikipedia.org/wiki/Radix_sort.
 */

# include <math.h>
# include <time.h>	/* for time(), used to seed the rng */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>	/* for usleep() */
# include <curses.h>
# include "deque.h"

# define delay 500000	/* delay in microseconds             */
# define m 1000		/* maximum value of integer in array */
# define n 40		/* number of integers                */
# define r 10		/* radix by which to sort            */


/*
 * Function:	main
 *
 * Description:	Driver function for the radix sort application.
 */

int main(void)
{
    int div, i, j, q, x, a[n], niter, digits;
    DEQUE *dp[r];


    initscr();
    curs_set(0);
    srand(time(0));

    div = 1;
    digits = ceil(log(m) / log(10));
    niter = ceil(log((m - 1) + 1) / log(r));


    /* Initialize the array and create the queues. */

    for (i = 0; i < n; i ++)
	a[i] = rand() % m;

    for (i = 0; i < r; i ++)
	dp[i] = createDeque();


    while (niter -- > 0) {


	/* Show the queues and the array. */

	clear();
	printw("Divisor: %d\n", div);

	for (i = 0; i < r; i ++) {
	    move(i + 2, 0);
	    printw("%d:", i);
	}

	move(2 + r + 1, 0);
	for (i = 0; i < n; i ++)
	    printw("%*d ", digits, a[i]);

	refresh();


	/* Take each number out the array and add it to the proper queue. */

	for (i = 0; i < n; i ++) {
	    q = (a[i] / div) % r;
	    addLast(dp[q], a[i]);


	    /* Show the number being added to the queue. */

	    move(q + 2, numItems(dp[q]) * (digits + 1));
	    printw("%*d", digits, a[i]);
	    refresh();
	    usleep(delay);
	}


	/* Now, move the numbers from the queues back into the array. */

	for (i = j = 0; i < r; i ++)
	    while (numItems(dp[i]) > 0) {
		x = removeFirst(dp[i]);
		a[j ++] = x;
	    }

	div = div * r;
	usleep(delay);
    }


    move(2 + r + 1, 0);
    for (i = 0; i < n; i ++)
	printw("%*d ", digits, a[i]);

    refresh();
    getchar();
    endwin();
    return EXIT_SUCCESS;
}
