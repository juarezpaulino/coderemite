/* Shoemaker's problem */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float time_per_fine;
    int original;
} job;

job jobs[1000];

int compare(const void *x, const void *y) {
    
    job *a = (job *) x;
    job *b = (job *) y;
    
    if (a -> time_per_fine < b -> time_per_fine)
        return (-1);
    else if (a -> time_per_fine > b -> time_per_fine)
        return (1);
        
    return ((a -> original) - (b -> original));
}


int main() {
    
    int cases, n_jobs;
    float  time, fine;
    int i;
    
    scanf("%d", &cases);
    while (cases) {
    
        scanf("%d", &n_jobs);
        for (i = 0; i < n_jobs; i++) {
            scanf("%f %f", &time, &fine);
            jobs[i].time_per_fine = time / fine;
            jobs[i].original = i+1;
        }
        
        qsort(jobs, n_jobs, sizeof(job), compare);
        
        for (i = 0; i < n_jobs-1; i++)
            printf("%d ", jobs[i].original);
        printf("%d\n", jobs[i].original);
        
        if (cases > 1)
            putchar('\n');
        cases--;
    }
    
    return 0;
}
    
