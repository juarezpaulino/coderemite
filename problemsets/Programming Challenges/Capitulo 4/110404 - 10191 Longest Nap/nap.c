/* Longest Nap */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hours;
    int minutes;
} time;

typedef struct {
    time start;
    time end;
} appoint;


appoint appointments[100];

int time_min(time t) {
    int min = 0;
    
    min += (t.hours * 60);
    min += t.minutes;
    
    return (min);
}

time min_time(int min) {
    time t;
    
    t.hours = min/60;
    t.minutes = min%60;
    
    return (t);
}

int start_compare(const void *x, const void *y) {
    
    return (time_min((*(appoint *)x).start) - time_min((*(appoint *)y).start));
}

int main() {
    
    int s, diff, nap;
    time start_nap, t;
    int i, day;
    char line[256];
    
    day = 1;
    while (scanf("%d", &s) != EOF) {
        for (i = 0; i < s; i++) {
            scanf("%d%*c%d", &appointments[i].start.hours, &appointments[i].start.minutes);
            scanf("%d%*c%d", &appointments[i].end.hours, &appointments[i].end.minutes);
            gets(line);
        }
        
        qsort(appointments, s, sizeof(appoint), start_compare);
        
        nap = 0;
        if (s > 0)
            nap = time_min(appointments[0].start) - 600;
        start_nap.hours = 10;
        start_nap.minutes = 0;
        for (i = 0; i < s - 1; i++) {
            diff = (time_min(appointments[i+1].start) - time_min(appointments[i].end));
            if (diff > nap) {
                nap = diff;
                start_nap = appointments[i].end;
            }
        }
        if (s > 0) {
            diff = 1080 - time_min(appointments[i].end);
            if (diff > nap) {
                nap = diff;
                start_nap = appointments[i].end;
            }
        }
        else
            nap = 480;
        
        t = min_time(nap);
        printf("Day #%d: the longest nap starts at %d:%02d and will last for ",
        day, start_nap.hours, start_nap.minutes);
        if (t.hours > 0)
            printf("%d hours and ", t.hours);
        printf("%d minutes.\n", t.minutes);
        day++;
    }  
    
    return 0;
}
