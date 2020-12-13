/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

/*
Let a[i] be the number of ways i pairs of people can shake hands.

It's easy tell that a[0] = 1, a[1] = 1, a[2] = 2.

For larger n, imagine choosing an arbitrary pair of people to shake hands. You've now divided the circle into two smaller circles (one of which may have 0 people in it). The number of ways you can arrange the rest of the people is the product of the answers for the two smaller circles.

So for example, to compute n = 3:

a[3] = a[0]*a[2] + a[1]*a[1] + a[2]*a[0]
a[4] = a[0]*a[3] + a[1]*a[2] + a[2]*a[1] + a[3][0]
*/


using namespace std;


int main() {

    int RET[11];
    RET[1] = 1;
    for (int i = 2; i <= 10; i++) RET[i] = RET[i-1]*(4*i-2) / (i+1);

    int N;
    bool first = 1;
    while (scanf("%d", &N) != EOF) {
        if (!first) putchar('\n');
        first = 0;
        printf("%d\n", RET[N]);
    }

    return 0;
}
