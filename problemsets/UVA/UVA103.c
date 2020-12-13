/* Stacking Boxes */

#include <stdio.h>
#include <stdlib.h>

#define MAXBOXES 30
#define MAXD 10

typedef struct {
   int b[MAXD];
   int original;
} box;

typedef struct {
   int cap;
   int pt;
} capacity;

box boxes[MAXBOXES];
capacity c[MAXBOXES];
int k, n;

int int_compare(int *x, int *y) {

   return (*y - *x);
}

int box_compare(box *x, box *y) {

   int j;

   for (j = 0; j < n; j++)
       if (x->b[j] != y->b[j])
           return (x->b[j] - y->b[j]);
}

int fit(int b1[], int b2[]) {

   int j;

   for (j = 0; j < n; j++)
       if (b1[j] >= b2[j])
           return 0;

   return 1;
}

void print_sequence(int index) {

   if (index == -1) return;

   print_sequence(c[index].pt);
   printf("%d ", boxes[index].original+1);
}


int main() {

   int i, j;
   int int_compare();
   int box_compare();
   int got;
   int max;
   int index;

   while (scanf("%d %d", &k, &n) != EOF) {

       for(i = 0; i < k; i++) {
           for (j = 0; j < n; j++)
               scanf("%d", &boxes[i].b[j]);
           boxes[i].original = i;
       }

       for (i = 0; i < k; i++)
           qsort(boxes[i].b, n, sizeof(int), int_compare);

       qsort(boxes, k, sizeof(box), box_compare);

       for (i = 0; i < k; i++) {
           c[i].cap = -1;
           c[i].pt = -1;
       }

       max = index = -1;

       for (i = 0; i < k; i++) {
           got = 0;
           for (j = i-1; j >= 0; j--)
               if (fit(boxes[j].b, boxes[i].b)) {
                   got = 1;
                   if (1 + c[j].cap > c[i].cap) {
                       c[i].cap = 1+c[j].cap;
                       c[i].pt = j;
                       if (c[i].cap > max) {
                           max = c[i].cap;
                           index = i;
                       }
                   }
               }
           if (!got) {
               c[i].cap = 1;
               c[i].pt = -1;
               if (max < 1) {
                   max =1;
                   index = i;
               }
           }
       }

       printf("%d\n", max);
       print_sequence(c[index].pt);
       printf("%d\n", boxes[index].original+1);
   }

   return 0;
}

