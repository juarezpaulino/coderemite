/* Jolly Jumpers */

#define MAX_NUMBERS 3002

#include <stdio.h>

int abs(int a) {
    
    if (a > 0)
        return(a);
    else
        return(-a);
}

int isJolly(int v[], int n) {
    
    int sequence[MAX_NUMBERS];
    int i;
    
    for (i = 1; i < n; i++)
        sequence[i] = 0;
    
    for (i = 1; i < n; i++) {
        if ((abs(v[i] - v[i-1]) > (n - 1)) || (abs(v[i] - v[i-1]) < 1))
            return 0;
        else
            sequence[abs(v[i] - v[i-1])] = 1;
    }
    
    for (i = 1; i < n; i++)
        if (!sequence[i])
            return 0;
    
    return 1;
}


int main() {
   
    int jolly[MAX_NUMBERS];
    int n, i, j;
    char cr;    
    
    while (scanf("%d%c", &n, &cr)!= EOF) {
        
	    if (n == 0)
            break;

        for (j = 0; j < n; j++) {
            scanf("%d%c", &i, &cr);
            jolly[j] = i;
        }
        
        if (n == 1)
            printf("Jolly\n");
        else if (isJolly(jolly, n))
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}
