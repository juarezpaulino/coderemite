/* Turkish Roulette */

#include <stdio.h>

#define MAXS 300
#define MAXB MAXS/2
#define INFINITY 0x3F3F3F3F


int s;
int b;
int X[MAXS];
int Y[MAXB];

int min(int x, int y) {

   return(x < y ? x : y);
}

int value(int ball, int s1, int s2) {

   return (ball * (s1+s2));
}

int DP(int A[]) {

   int opt[MAXB][MAXS];
   int i, j;

   for (i = 0; i < b-1; i++)
       for (j = 0; j < s-2; j++)
           opt[i][j] = 0;

   opt[0][0] = value(Y[0], A[0], A[1]);
   for (j = 1; j < s-2*(b-2)-3; j++)
       opt[0][j] = min(opt[0][j-1], value(Y[0], A[j], A[j+1]));

   for (i = 1, j = 2; i < b-1; i++, j+=2)
       opt[i][j] = opt[i-1][j-2] + value(Y[i], A[j], A[j+1]);

   for (i = 1; i < b-1; i++)
       for (j = i*2+1; j < s-2*(b-i-2)-3; j++)
           opt[i][j] = min(opt[i][j-1], opt[i-1][j-2]+value(Y[i], A[j], A[j+1]));

   return (opt[b-2][s-4]);
}


int main() {

   int i, j;
   int A[MAXS];    /* Vector to apply DP */
   int opt;
   int v;
   int maxprofit;

   while (scanf("%d %d", &s,  &b)) {

       if ((s == 0) && (b == 0))
           break;

       for (i = 0; i < s; i++)
           scanf("%d", &X[i]);

       for (i = 0; i < b; i++)
           scanf("%d", &Y[i]);

       maxprofit = INFINITY;
       for (i = 0; i < s; i++) {
           for (j = i+2; j < i+s; j++)
               A[j-(i+2)] = X[j%s];
           opt = DP(A);
           if ((v = value(Y[b-1], X[i], X[(i+1)%s]) + opt) < maxprofit)
               maxprofit = v;
       }

       printf("%d\n", -maxprofit);
   }

   return 0;
}

