/* Ecological Bin Packing */

#include <stdio.h>

#define MAXBIN 9
#define MAXMOVE 6

char possible[][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main() {

   int bin[MAXBIN];
   int move[MAXMOVE];
   int i;
   int min, index;
   int sum;

   while (scanf("%d", &bin[0]) != EOF) {

       sum = bin[0];
       for (i = 1; i < MAXBIN; i++) {
           scanf("%d", &bin[i]);
           sum += bin[i];
       }

       move[0] = sum-bin[0]-bin[5]-bin[7];
       move[1] = sum-bin[0]-bin[4]-bin[8];
       move[2] = sum-bin[2]-bin[3]-bin[7];
       move[3] = sum-bin[2]-bin[4]-bin[6];
       move[4] = sum-bin[1]-bin[3]-bin[8];
       move[5] = sum-bin[1]-bin[5]-bin[6];

       min = move[0];
       index = 0;
       for (i = 1; i < MAXMOVE; i++)
           if (min > move[i]) {
               min = move[i];
               index = i;
           }

       printf("%s %d\n", possible[index], min);
   }

   return 0;
}