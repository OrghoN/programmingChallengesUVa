#include <stdio.h>

int cache[1000000];
// int init;

long next(long n) {
        if (n % 2 == 0)
                return n / 2; // if n is even
        else
                return 3 * n + 1; // if n is odd
}

// cache for already computed cycle lengths

int cycleLength(long n) {
        if (n == 1) {
                return 1;
        }

        if (n < 1000000 && cache[(int)n] != 0)
                return cache[(int)n];

        // the cycle length of the current number is 1 greater
        // than the cycle length of the next number
        int length = 1 + cycleLength(next(n));

        // we cache the result if the
        // current number is not too big
        if (n < 1000000)
                cache[(int)n] = length;

        return length;
}

int main()
{
        int m,n,max,temp;
        int mOriginal,nOriginal;
        int i;

        for(int init = 0; init < 1000000; init++ ) {
                cache[init] = 0; /* set element at location i to i + 100 */
        }


        while (scanf("%d %d\n",&m,&n)==2) {

                /* remember original order of entries for output */
                mOriginal = m;
                nOriginal = n;

                /* swap if out of order */
                if (m > n) {
                        temp = m;
                        m = n;
                        n = temp;
                }

                max = -1;
                for(i=m+1; i<=n; i++) {
                        temp = cycleLength(i);
                        if (temp > max)
                                max = temp;
                }

                printf("%d %d %d\n",mOriginal,nOriginal,max);
                // printf("%d %d \n",mOriginal,nOriginal);
        }
        return(0);
}
