/* Power Generation */

#include <stdio.h>
#include <math.h>

#define MAXP 10001
#define MAXG 1001
#define K 900
#define C 5
#define MAXINT 1000000000 

#define distance(x1, y1, x2, y2) (((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)))

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    int parent;
    int x, y;    
    int p;
    int nf;
} plant;


int n, c;
plant p[MAXP];
int point[MAXG][MAXG];
int companies;

int dist_parent(int pos) {
    
    register int i;
    register int pai;
    register int x, y;
    register int min, d;
    
    x = p[pos].x;
    y = p[pos].y;
    
    min = MAXINT;
    pai = -1;
    for (i = 0; i < pos; i++)
        if ((d = distance(x, y, p[i].x, p[i].y)) < min) {
            min = d;
            pai = i;
        }
    
    return (pai);
}

int circle_parent(int pos) {

    register int i, l;
    register int j, pai;
    register int x, y;
    register int min, d;
    bool flag;
    bool jump;
    
    flag = TRUE;
    l = C;
    x = p[pos].x;
    y = p[pos].y;
    pai = MAXP;
    min = MAXINT;
    while (flag) {
        for (i = x-l; i <= x+l; i++) {
            jump = FALSE;
            for (j = y-l; j <= y+l; j++) {
                if ((i >= 0) && (i < MAXG) && (j >= 0) && (j < MAXG)) {
                    d = distance(x, y, i, j);
                    if (d <= (l*l)) {
                        if ((d < ((l-C)*(l-C))) && (!jump)) {
                            j = 2*y-j;
                            jump = TRUE;
                            continue;
                        }
                        if (point[i][j] != -1) {
                            flag = FALSE;
                            if (d < min) {
                                min = d;
                                pai = point[i][j];
                            }
                            else if (d == min) 
                                if (point[i][j] < pai) 
                                    pai = point[i][j];
                        }
                    }
                }
            }
        }
        l += C;
    }       
    
    return (pai);
}

void greedy() {
    
    int leaf[MAXP];
    register int i, nleaf;
    plant *v;
    
    companies = 0;
    nleaf = 0;
    for (i = 0; i < n; i++)
        if (p[i].nf == 0)
            leaf[nleaf++] = i;
    
    for (i = 0; i < nleaf; i++) {
        v = &p[leaf[i]];
        
        if (v->p >= c) companies++;
        else p[v->parent].p += v->p;
        
        p[v->parent].nf--;
        if (p[v->parent].nf == 0)
            leaf[nleaf++] = v->parent;
    }
}


int main() {

    register int i, j, pai, total;
    int x, y;

    while (scanf("%d %d", &n, &c)) {
        
        if ((n == 0) && (c == 0))
            break;

        if (n >= K)
            for (i = 0; i < MAXG; i++)
                for (j = 0; j < MAXG; j++)
                    point[i][j] = -1;

        total = 0;
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &p[i].p);
            p[i].x = x;
            p[i].y = y;
            p[i].nf = 0;
            total += p[i].p;
            if (i == 0)
                pai = -1;
            else {
                if (i < K)
                    pai = dist_parent(i);
                else
                    pai = circle_parent(i);
                p[pai].nf++;
            }
            point[x][y] = i;
            p[i].parent = pai;
        }
        
        if (total < c)
            printf("0\n");
        else if (total < c*2)
            printf("1\n");
        else {
            greedy();
            printf("%d\n", companies);
        }
    }
        
    return 0;
}
