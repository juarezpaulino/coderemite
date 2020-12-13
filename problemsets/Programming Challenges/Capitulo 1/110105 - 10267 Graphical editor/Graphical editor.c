#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 250
#define MAX_LINES 250

#define swap(a,b) a^=b^=a^=b

char picture[MAX_LINES][MAX_ROWS];

struct coord {
    int x;
    int y;
};

void C(int m, int n) {
    int i,j;
    for (i=0; i <= n; i++)
        for (j=0; j <= m; j++)
            picture[i][j] = 'O';
}

void I(int m, int n) {
    C(m,n);    
}

void L(int x, int y, char c) {
        picture[y][x] = c;
}

void V(int x, int y1, int y2, char c) {
    int i;
    for (i = y1; i <= y2; i++)
        picture[i][x] = c;        
}

void H(int x1, int x2, int y, char c) {
    int j;
    for (j = x1; j <= x2; j++)
        picture[y][j] = c;        
}

void K(int x1, int y1, int x2, int y2, char c) {
    int i,j;
    for (i = y1; i <= y2; i++)
        for (j = x1; j <= x2; j++)
            picture[i][j] = c;        
}

void F(int m, int n, int x, int y, char c, char fix){
    
    struct coord *vector = (struct coord *) malloc(sizeof(struct coord)*(m+1)*(n+1));
    struct coord aux;
    int i;
    int cont;
    
    aux.x = x;
    aux.y = y;
    vector[0] = aux;
    cont = -1;
    i = 0;
    picture[aux.y][aux.x] = c;
    
    while(cont < i) {
        cont++;
        if(aux.x - 1 >= 0) {
            if (picture[aux.y][aux.x - 1] == fix) {
                i++;
                vector[i].x  = aux.x - 1;
                vector[i].y  = aux.y;
                picture[aux.y][aux.x - 1] = c;
            }
        } 
        if(aux.y - 1 >= 0){
            if (picture[aux.y - 1][aux.x] == fix) {
                i++;
                vector[i].x  = aux.x;
                vector[i].y  = aux.y - 1;
                picture[aux.y - 1][aux.x] = c;
            }
        }
        if (aux.x + 1 <= m) {
            if (picture[aux.y][aux.x + 1] == fix) {
                i++;
                vector[i].x  = aux.x + 1;
                vector[i].y  = aux.y;
                picture[aux.y][aux.x + 1] = c;
            }
        }
        if (aux.y + 1 <= n) {
            if (picture[aux.y + 1][aux.x] == fix) {
                i++;
                vector[i].x  = aux.x;
                vector[i].y  = aux.y+1;
                picture[aux.y + 1][aux.x] = c;
            }
        }
        if (cont < i) 
            aux = vector[cont+1];
    }
    free(vector);
}

int main() {
    
    int n,m,x1,y1,x2,y2;
    int loop1, loop2;
    char *name = (char *) malloc (sizeof(char) * 25);
    char command, cr;
    
    n = m = 0;
    scanf("%c", &command);
    while(command != 'X') {
        switch(command) {
            case 'I': 
                scanf(" %d %d",&m,&n);
                I(m - 1,n - 1);
                break;
            case 'C':
                C(m - 1,n - 1);
                break;
            case 'L':
                scanf(" %d %d %c",&x1,&y1,&cr);
                L(x1-1,y1-1,cr);
                break;
            case 'V':
                scanf(" %d %d %d %c",&x1,&y1,&y2,&cr);
                if (y1 > y2)
                    swap(y1,y2);
                V(x1-1,y1-1,y2-1,cr);
                break;
            case 'H':
                scanf(" %d %d %d %c",&x1,&x2,&y1,&cr);
                if (x1 > x2)
                    swap(x1,x2);
                H(x1-1,x2-1,y1-1,cr);
                break;
            case 'K':
                scanf(" %d %d %d %d %c",&x1,&y1,&x2,&y2,&cr);
                K(x1-1,y1-1,x2-1,y2-1,cr);
                break;
            case 'F':
                scanf(" %d %d %c",&x1,&y1,&cr);
                if (cr == picture[y1 - 1][x1 - 1])
                    break;
                F(m - 1,n - 1,x1-1,y1-1,cr, picture[y1-1][x1-1]);
                break;
            case 'S':
                scanf("%s",name);
                printf("%s\n", name);
                for (loop1 = 0; loop1 < n; loop1++) {
                    for (loop2 = 0; loop2 < m; loop2++)
                        printf("%c", picture[loop1][loop2]);
                    putchar('\n');
                }
                break;
            case 'X':
                break;
            default:
                if (command != '\n')
                    while(getchar() != '\n');
        }
        if (command != 'X')
            scanf("%c", &command);
    }
    free(name);
    
    return 0;    
}
