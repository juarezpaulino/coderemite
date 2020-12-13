/* Bee Maja */

#include <stdio.h>

#define MAXDIRECTION 6
#define MAXPOINTS 100001

typedef struct {
    int x;
    int y;
} point;

point pt[MAXPOINTS];

void move(int dir, int src, int des) {
    
    switch (dir) {
        /* Up */
        case 0:    
            pt[des].x = pt[src].x;
            pt[des].y = pt[src].y-1;
            break;
        /* Up right */
        case 1:
            pt[des].x = pt[src].x+1;
            pt[des].y = pt[src].y-1;
            break;
        /* Down right */
        case 2:
            pt[des].x = pt[src].x+1;
            pt[des].y = pt[src].y;
            break;
        /* Down */
        case 3:
            pt[des].x = pt[src].x;
            pt[des].y = pt[src].y+1;
            break;
        /* Down left */
        case 4:
            pt[des].x = pt[src].x-1;
            pt[des].y = pt[src].y+1;
            break;
        /* Up left */
        case 5:
            pt[des].x = pt[src].x-1;
            pt[des].y = pt[src].y;
            break;
    }
}


int main() {

    int src, des;
    int dir;
    int i, j, gap;

    pt[1].x = pt[1].y = 0;
    
    /* First hexagon */
    dir = 3;
    for (des = 2; des <= 7; des++) {
        move(dir, 1, des);
        dir = (dir+1)%MAXDIRECTION;
    }
    
    dir = 2;
    src = 2;
    des = 8;
    gap = 0;
    /* Complete the system */
    while (des <= MAXPOINTS) {
        for (i = 0; i < 6; i++) {
            if (des > MAXPOINTS)
                break;
            move(dir, src, des);
            move((dir+1)%MAXDIRECTION, src, des+1);
            des += 2;
            dir = (dir+1)%MAXDIRECTION;
            src++;
            for (j = 0; j < gap; j++) {
                if (des > MAXPOINTS)
                    break;
                move(dir, src, des);
                src++;
                des++;
            }
        }
        gap++;
    }
    
    while (scanf("%d", &src) != EOF)
        printf("%d %d\n", pt[src].x, pt[src].y);
    
    return 0;
}
