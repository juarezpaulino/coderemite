/* Birthday Cake */

#include <stdio.h>
#include <stdlib.h>

#define RANGE 500
#define MAXCHERRY 100

typedef int point[2];
#define X 0
#define Y 1


int main() {
 
    int N;
    int i;
    point cherry[MAXCHERRY];
    int side1, side2;
    int A, B;
    
    srand(time(NULL));
    
    while (scanf("%d", &N)) {
        
        if (N == 0)
            break;
        
        for (i = 0; i < 2*N; i++)
            scanf("%d %d", &cherry[i][X], &cherry[i][Y]);
        
        while (1) {
            A = rand() % RANGE+1;
            if (rand() % 2)
                A *= -1;
            B = rand() % RANGE+1;
            if (rand() % 2)
                B *= -1;
            
            side1 = side2 = 0;
            for (i = 0; (i < 2*N) && (side1 <= N) && (side2 <= N); i++)
                if (A*cherry[i][X] + B*cherry[i][Y] > 0)
                    side1++;
                else if (A*cherry[i][X] + B*cherry[i][Y] < 0)
                    side2++;

            if (side1 == side2)
                break;
        }
        
        printf("%d %d\n", A, B);
    }
    return 0;
}
