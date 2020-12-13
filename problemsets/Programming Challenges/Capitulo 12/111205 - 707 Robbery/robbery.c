/* Robbery */

#include <stdio.h>

typedef char state;
#define POSSIBLE 0
#define OBSERVED 1
#define OCCUPIED 2

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXTIME 101
#define MAXWIDTH 101
#define MAXHEIGHT 101

struct {
    char x;
    char y;
    bool unique;
} parent[MAXTIME][MAXHEIGHT][MAXWIDTH];

bool one[MAXTIME];

state city[MAXTIME][MAXHEIGHT][MAXWIDTH];

void initialize_city(int t, int h, int w) {

    int k, i, j;
    
    for (k = 1; k <= t; k++) {
        one[k] = FALSE;
        for (i = 1; i <= h; i++)
            for (j = 1; j <= w; j++) {
                city[k][i][j] = POSSIBLE;
                parent[k][i][j].x = -1;
                parent[k][i][j].y = -1;
            }
    }
}

void fill_observed(int ti, int Li, int Ti, int Ri, int Bi) {

    int i, j;
    
    for (i = Ti; i <= Bi; i++)
        for (j = Li; j <= Ri; j++)
            city[ti][i][j] = OBSERVED;
}

bool islegal(int i, int j, int h, int w, int ti) {

    if ((i > 0) && (i <= h) && (j > 0) && (j <= w)) {
        if (city[ti+1][i][j] != OBSERVED)
            return TRUE;
        else
            return FALSE;
    }
    else
        return FALSE;
}

void reconstruct_path(int x, int y, int t, bool legal) {

    if (parent[t][y][x].x == -1) return;
    
    if (one[t-1] == TRUE)
        legal = TRUE;
    
    if (parent[t][y][x].unique == TRUE) {
        reconstruct_path(parent[t][y][x].x, parent[t][y][x].y, t-1, legal);
        if (legal == TRUE)
            printf("Time step %d: The robber has been at %d,%d.\n", t-1, 
            parent[t][y][x].x, parent[t][y][x].y);
    }
    else 
        reconstruct_path(parent[t][y][x].x, parent[t][y][x].y, t-1, FALSE);
}

void simulate(int t, int h, int w) {
    
    int i, j, k, m;
    int x, y, xi, yi, ti;
    int count, first;
    
    if (t == 1) {
        count = 0;
        for (i = 1; i <= h; i++)
            for (j = 1; j <= w; j++)
                if (city[1][i][j] == POSSIBLE) {
                    x = j;
                    y = i;
                    count++;
                    if (count > 1) {
                        printf("Nothing known.\n");
                        return;
                    }
                }
        if (count == 0) {
            printf("The robber has escaped.\n");
            return;
        }
        else {
            printf("Time step 1: The robber has been at %d,%d.\n", x, y);
            return;
        }
    }
    else {
        ti = -1;
        count = 0;
        first = 0;;
        for (i = 1; i <= h; i++)
            for (j = 1; j <= w; j++)
                if (city[1][i][j] == POSSIBLE) {
                    first++;
                    if (islegal(i, j, h, w, 1)) {
                        if (city[2][i][j] == OCCUPIED)
                            parent[2][i][j].unique = FALSE;
                        else {
                            count++;
                            city[2][i][j] = OCCUPIED;
                            x = j;
                            y = i;
                            parent[2][i][j].x = j;
                            parent[2][i][j].y = i;
                            parent[2][i][j].unique = TRUE;
                        }
                    }
                    for (m = -1; m <= 1; m+=2) {
                        if (islegal(i, j+m, h, w, 1)) {
                            if (city[2][i][j+m] == OCCUPIED)
                                parent[2][i][j+m].unique = FALSE;
                            else {
                                count++;
                                city[2][i][j+m] = OCCUPIED;
                                x = j+m;
                                y = i;
                                parent[2][i][j+m].x = j;
                                parent[2][i][j+m].y = i;
                                parent[2][i][j+m].unique = TRUE;
                            }
                        }
                        if (islegal(i+m, j, h, w, 1)) {
                            if (city[2][i+m][j] == OCCUPIED)
                                parent[2][i+m][j].unique = FALSE;
                            else {
                                count++;
                                city[2][i+m][j] = OCCUPIED;
                                x = j;
                                y = i+m;
                                parent[2][i+m][j].x = j;
                                parent[2][i+m][j].y = i;
                                parent[2][i+m][j].unique = TRUE;
                            }
                        }
                    }
                }
        if (count == 0) {
            printf("The robber has escaped.\n");
            return;
        }
        else if (count == 1) {
            one[2] = TRUE;
            ti = 2;
            xi = x;
            yi = y;
        }
        if (first == 1)
            one[1] = TRUE;
        
        for (k = 2; k <= t-1; k++) {
            count = 0;
            for (i = 1; i <= h; i++)
                for (j = 1; j <= w; j++)
                    if (city[k][i][j] == OCCUPIED) {
                        if (islegal(i, j, h, w, k)) {
                            if (city[k+1][i][j] == OCCUPIED)
                                parent[k+1][i][j].unique = FALSE;
                            else {
                                count++;
                                city[k+1][i][j] = OCCUPIED;
                                x = j;
                                y = i;
                                parent[k+1][i][j].x = j;
                                parent[k+1][i][j].y = i;
                                parent[k+1][i][j].unique = TRUE;
                            }
                        }
                        for (m = -1; m <= 1; m+=2) {
                            if (islegal(i, j+m, h, w, k)) {
                                if (city[k+1][i][j+m] == OCCUPIED)
                                    parent[k+1][i][j+m].unique = FALSE;
                                else {
                                    count++;
                                    city[k+1][i][j+m] = OCCUPIED;
                                    x = j+m;
                                    y = i;
                                    parent[k+1][i][j+m].x = j;
                                    parent[k+1][i][j+m].y = i;
                                    parent[k+1][i][j+m].unique = TRUE;
                                }
                            }
                            if (islegal(i+m, j, h, w, k)) {
                                if (city[k+1][i+m][j] == OCCUPIED)
                                    parent[k+1][i+m][j].unique = FALSE;
                                else {
                                    count++;
                                    city[k+1][i+m][j] = OCCUPIED;
                                    x = j;
                                    y = i+m;
                                    parent[k+1][i+m][j].x = j;
                                    parent[k+1][i+m][j].y = i;
                                    parent[k+1][i+m][j].unique = TRUE;
                                }
                            }
                        }
                    }
            if (count == 0) {
                printf("The robber has escaped.\n");
                return;
            }
            else if (count == 1) {
                one[k+1] = TRUE;
                ti = k+1;
                xi = x;
                yi = y;
            }
        }
        if (ti == -1) {
            printf("Nothing known.\n");
            return;
        }
        else {
            reconstruct_path(xi, yi, ti, TRUE);
            printf("Time step %d: The robber has been at %d,%d.\n", ti, xi, yi);
        }
    }
    
}


int main() {

    int h, w, t;
    int messages;
    int ti, Li, Ti, Ri, Bi;
    int i;
    int x, y;
    int cases;
    
    cases = 1;
    while (scanf("%d %d %d", &w, &h, &t)) {
        if ((w == 0) && (h == 0) && (t == 0))
            break;
        
        initialize_city(t, h, w);

        scanf("%d", &messages);
        
        for (i = 0; i < messages; i++) {
            scanf("%d %d %d %d %d", &ti, &Li, &Ti, &Ri, &Bi);
            fill_observed(ti, Li, Ti, Ri, Bi);
        }
        
        printf("Robbery #%d:\n", cases);
        cases++;
        simulate(t, h, w);
        putchar('\n');
    }    
    for (i = 0; i < 10000000; i++);
    return 0;
}
    
