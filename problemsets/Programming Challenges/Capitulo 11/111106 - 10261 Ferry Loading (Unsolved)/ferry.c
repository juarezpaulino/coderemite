/* Ferry Loading */

#include <stdio.h>

#define MAXCARS 201
#define MAXVALUE 20000
#define LEFT 1
#define UP 2

typedef char bool;
#define TRUE 1
#define FALSE 0


typedef struct {
    unsigned port;
    unsigned starboard;
    int parent;
} cell;

cell m[MAXCARS][MAXCARS];

void reconstruct_path(int i, int j) {

    if (m[i][j].parent == -1) return;
    
    if (m[i][j].parent == UP) {
        reconstruct_path(i-1, j);
        printf("port\n");
        return;
    }
    
    if (m[i][j].parent == LEFT) {
        reconstruct_path(i, j-1);
        printf("starboard\n");
    }
    
    if (m[i][j].parent == -10) {
        m[i][j].parent = 0;
        printf("%d", 1/m[i][j].parent);
    }
}


int main() {
 
    int i, j;
    int cases;
    int cars[MAXCARS], ncars;
    int length;
    int aux, xcars, ycars;
    bool change;
    
    scanf("%d", &cases);
    while (cases) {
        
        scanf("%d", &length);
        length *= 100;
        
        ncars = 1;
        while (1) {
            scanf("%d", &aux);
            if (aux == 0)
                break;
            if (ncars <= 200) {
                cars[ncars] = aux;
                ncars++;
            }
        }

        xcars = ycars = 0;
        
        m[0][0].port = m[0][0].starboard = 0;
        m[0][0].parent = -1;
        for (j = 1; j < ncars; j++) {
            aux = m[0][j-1].starboard + cars[j];
            if (aux <= length) {
                m[0][j].port = 0;
                m[0][j].starboard = aux;
                m[0][j].parent = LEFT;
                xcars = j;
            }
            else {
                m[0][j].port = MAXVALUE;
                m[0][j].starboard = MAXVALUE;
                m[0][j].parent = -10;
            }
        }
        for (i = 1; i < ncars; i++) {
            aux = m[i-1][0].port + cars[i];
            if (aux <= length) {
                m[i][0].port = aux;
                m[i][0].starboard = 0;
                m[i][0].parent = UP;
            }
            else {
                m[i][0].port = MAXVALUE;
                m[i][0].starboard = MAXVALUE;
                m[i][0].parent = -10;
            }
        }
        
        for (i = 1; i < ncars; i++) {
            change = FALSE;
            for (j = 1; j < ncars; j++) {
                if (i+j < ncars) {
                    if ((aux = m[i][j-1].starboard + cars[i+j]) <= length) {
                        m[i][j].starboard = aux;
                        m[i][j].port = m[i][j-1].port;
                        m[i][j].parent = LEFT;
                        change = TRUE;
                        if ((i+j) > xcars+ycars) {
                            ycars = i;
                            xcars = j;
                        }
                    }
                    else if ((aux = m[i-1][j].port + cars[i+j]) <= length) {
                        m[i][j].port = aux;
                        m[i][j].starboard = m[i-1][j].starboard;
                        m[i][j].parent = UP;
                        change = TRUE;
                        if ((i+j) > xcars+ycars) {
                            ycars = i;
                            xcars = j;
                        }
                    }
                    else {
                        m[i][j].port = MAXVALUE;
                        m[i][j].starboard = MAXVALUE;
                        m[i][j].parent = -10;
                    }
                }
                else {
                    m[i][j].port = MAXVALUE;
                    m[i][j].starboard = MAXVALUE;
                    m[i][j].parent = -10;
                }
            }
            if (!change)
                break;
        }
        /*for (i = 0; i < ncars; i++) {
            for (j = 0; j < ncars; j++)
                printf("%5d/%5d  ", m[i][j].port, m[i][j].starboard);
            putchar('\n');
        }*/
        
        printf("%d\n", xcars+ycars);
        reconstruct_path(ycars, xcars);
        
        cases--;
        if (cases)
            putchar('\n');
    }       
    for (i = 0; i < 100000000; i++);
    return 0;
}
