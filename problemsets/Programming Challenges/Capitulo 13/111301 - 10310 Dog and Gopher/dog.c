/* Dog and Gopher */

#include <stdio.h>
#include <math.h>

typedef double point[2];
#define X 0
#define Y 1

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXHOLES 1000


double distance(point a, point b) {
    
    return (sqrt(((a[Y] - b[Y])*(a[Y] - b[Y])) + ((a[X] - b[X])*(a[X] - b[X]))));
}


int main() {
    
    point dog;
    point gopher;
    point hole;
    point escape;
    bool escaped;
    int n, i;
    double d_dog;
    double d_gopher;
    
    while(scanf("%d", &n) != EOF) {
        
        scanf("%lf %lf", &gopher[X], &gopher[Y]);
        scanf("%lf %lf", &dog[X], &dog[Y]);
        
        escaped = FALSE;
        for (i = 0; i < n; i++) {
            scanf("%lf %lf", &hole[X], &hole[Y]);
            if (escaped == FALSE) {
                d_dog = distance(dog, hole);
                d_gopher = distance(gopher, hole);
            
                if ((d_dog/2.0) - d_gopher >= 0) {
                    escaped = TRUE;
                    escape[X] = hole[X];
                    escape[Y] = hole[Y];
                }
            }
        }
        
        if (escaped == TRUE)
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",
            escape[X], escape[Y]);
        else
            printf("The gopher cannot escape.\n");
    }
    
    return 0;
}
