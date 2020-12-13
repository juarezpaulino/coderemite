/* Slash Maze */

#include <stdio.h>

#define C

#ifdef C
typedef char bool;
#define TRUE 1
#define FALSE 0
#endif

#define MAXHEIGHT 75
#define MAXWIDTH 150 

typedef struct {
    int x;
    int y;
} coord;

char slashes[MAXHEIGHT][MAXWIDTH/2];
bool discovered[MAXHEIGHT][MAXWIDTH];
coord parent[MAXHEIGHT*MAXWIDTH];
int size, cycles;

bool compare_coord(coord x, coord y) {
    
    if (x.x != y.x)
        return (FALSE);
    if (x.y != y.y)
        return (FALSE);
    return TRUE;
}

void read_matrix(int lines, int columns) {
    
    int i, j;
    
    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++)
            slashes[i][j] = getchar();
        getchar();
    }
}

void initialize_search(int h, int w) {
    
    int i, j;
    
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++) {
            discovered[i][j] = FALSE;
            parent[(i*w)+j].x = -1;
            parent[(i*w)+j].y = -1;
        }
    size = -1;
    cycles = 0;
}

void construct_candidates(coord c[], int *ncandidates, coord pos, int h, int w, coord last) {
    
    coord aux;
    
    *ncandidates = 0;
    
    if (slashes[pos.x][pos.y/2] == '\\') {
        if (pos.y % 2) {
            if ((pos.y + 1) < w) {
                aux.x = pos.x;
                aux.y = pos.y+1;
                if (!compare_coord(aux, last)) {
                    c[*ncandidates] = aux;
                    (*ncandidates)++;
                }
            }
            if (pos.x - 1 >= 0) {
                if (slashes[pos.x-1][pos.y/2] == '\\') {
                    aux.x = pos.x-1;
                    aux.y = pos.y-1;
                    if (!compare_coord(aux, last)) {
                        c[*ncandidates] = aux;
                        (*ncandidates)++;
                    }
                }
                else {
                    aux.x = pos.x-1;
                    aux.y = pos.y;
                    if (!compare_coord(aux, last)) {
                        c[*ncandidates] = aux;
                        (*ncandidates)++;
                    }
                }
            }
        }
        else {
            if ((pos.y - 1) >= 0) {
                aux.x = pos.x;
                aux.y = pos.y-1;
                if (!compare_coord(aux, last)) {
                    c[*ncandidates] = aux;
                    (*ncandidates)++;
                }
            }
            if (pos.x + 1 < h) {
                if (slashes[pos.x+1][pos.y/2] == '\\') {
                    aux.x = pos.x+1;
                    aux.y = pos.y+1;
                    if (!compare_coord(aux, last)) {
                        c[*ncandidates] = aux;
                        (*ncandidates)++;
                    }
                }
                else {
                    aux.x = pos.x+1;
                    aux.y = pos.y;
                    if (!compare_coord(aux, last)) {
                        c[*ncandidates] = aux;
                        (*ncandidates)++;
                    }
                }
            }
        }    
    }
    else {
        if (pos.y % 2) {
            if ((pos.y + 1) < w) {
                aux.x = pos.x;
                aux.y = pos.y+1;
                if (!compare_coord(aux, last)) {
                    c[*ncandidates] = aux;
                    (*ncandidates)++;
                }
            }
            if (pos.x + 1 < h) {
                if (slashes[pos.x+1][pos.y/2] == '\\') {
                    aux.x = pos.x+1;
                    aux.y = pos.y;
                    if (!compare_coord(aux, last)) {
                        c[*ncandidates] = aux;
                        (*ncandidates)++;
                    }
                }
                else {
                    aux.x = pos.x+1;
                    aux.y = pos.y-1;
                    if (!compare_coord(aux, last)) {
                        c[*ncandidates] = aux;
                        (*ncandidates)++;
                    }
                }
            }
        }
        else {
            if ((pos.y - 1) >= 0) {
                aux.x = pos.x;
                aux.y = pos.y-1;
                if (!compare_coord(aux, last)) {
                    c[*ncandidates] = aux;
                    (*ncandidates)++;
                }
            }
            if (pos.x - 1 >= 0) {
                if (slashes[pos.x-1][pos.y/2] == '\\') {
                    aux.x = pos.x-1;
                    aux.y = pos.y;
                    if (!compare_coord(aux, last)) {
                        c[*ncandidates] = aux;
                        (*ncandidates)++;
                    }
                }
                else {
                    aux.x = pos.x-1;
                    aux.y = pos.y+1;
                    if (!compare_coord(aux, last)) {
                        c[*ncandidates] = aux;
                        (*ncandidates)++;
                    }
                }
            }
        }
    }
}

void find_path(coord start, coord end, coord parents[], int h, int w, int *lenght) {
    
    *lenght = 0;
    if (compare_coord(start, end) || ((end.x == -1) && (end.y == -1)))
        (*lenght)++;
    else {
        find_path(start, parents[(end.x*w)+end.y], parents, h, w, lenght);
        (*lenght)++;
    }
}

void process_edge(coord x, coord y, int h, int w) {
    
    int lenght;
    
    if (!compare_coord(parent[(x.x*w)+x.y],y)) {
        find_path(y, x, parent, h, w, &lenght);
        if (lenght > size)
            size = lenght;
        cycles++;
    }
}

void dfs(coord pos, int h, int w, coord last) {

    coord c[2];
    int ncandidates, i;
    
    discovered[pos.x][pos.y] = TRUE;
    
    construct_candidates(c, &ncandidates, pos, h, w, last);
    for (i = 0; i < ncandidates; i++) {
        if (discovered[c[i].x][c[i].y] == FALSE) {
            parent[(c[i].x*w)+c[i].y] = pos;
            dfs(c[i], h, w, pos);
        }
        else
            if ((last.x != -1) && (last.y != -1))
                process_edge(pos, c[i], h, w);    
    }
}

void connected_components(int h, int w) {

    int i, j;
    coord pos, last;
    
    initialize_search(h, w);
    
    last.x = -1;
    last.y = -1;
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            if (discovered[i][j] == FALSE) {
                pos.x = i;
                pos.y = j;
                dfs(pos, h, w, last);
            }
}

int main() {
    
    int w, h, maze, i, j;
    
    maze = 1;
    while (scanf("%d %d", &w, &h)) {
        getchar();
        
        if ((w == 0) && (h == 0))
            break;
        
        read_matrix(h, w);
        connected_components(h, w*2);
        
        printf("Maze #%d:\n", maze);
        if (cycles)
            printf("%d Cycles; the longest has length %d.\n\n", cycles, size);
        else
            printf("There are no cycles.\n\n");
        maze++;
    }
    
    return 0;
}
