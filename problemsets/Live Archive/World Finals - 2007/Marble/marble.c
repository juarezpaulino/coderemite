/* Marble Game */

#include <stdio.h>
#include <stdlib.h>

#define MAXG 4
#define MAXH 5011
#define INF 1000000

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    char ball[MAXG][MAXG];
    char nball;
} state;

typedef struct pt {
    state st;
    int deep;
    struct pt *prox;
} statept;

typedef struct {
    state st[MAXH];
    char hole[MAXH][MAXG][MAXG];
    char k[MAXH];
    int first, last;
    int c;
} queue;

char hole[MAXG][MAXG];

bool wall[MAXG][MAXG][MAXG][MAXG];

bool impossible;
int move;
bool getdeep;

int N, M, W;

state st;
queue q;

statept *hash[MAXH];

void enqueue(queue *q, state *st, char hole[][MAXG], char k) {

    int i, j;
    
    q->last = (q->last+1)%MAXH;
    q->st[q->last] = *st;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            q->hole[q->last][i][j] = hole[i][j];
    q->k[q->last] = k;
    q->c++;
}

void dequeue(queue *q, state *st, char hole[][MAXG], char *k) {
    
    int i, j;
    
    *st = q->st[q->first];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            hole[i][j] = q->hole[q->first][i][j];
    *k = q->k[q->first];
    q->first = (q->first+1)%MAXH;
    q->c--;
}

bool empty(queue *q) {
    
    return((q->c == 0)? TRUE:FALSE);
}

int fh(state *st) {

    int i, j;
    int sum;
    
    sum = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (st->ball[i][j])
                sum += ((i*N)+j)+st->ball[i][j];
    
    return(sum %MAXH);
}

int cmp_state(state *a, state *b) {
    
    int i, j;
    
    if (a->nball != b->nball)
        return(1);
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (a->ball[i][j] != b->ball[i][j])
                return (1);
    return(0);
}

int BFS(queue *q) {
    
    int i, j, l;
    int x;
    int pos, h;
    bool getm;
    statept *pt, *ptaux;
    char k;
    char hole[MAXG][MAXG], newhole[MAXG][MAXG];
    state st, newst;
    
    while (!empty(q)) {
        
        dequeue(q, &st, hole, &k);
        
        if (st.nball == 0)
            return(k);
        
        /* Move up */
        getm = TRUE;
        newst.nball = st.nball;
        for (j = 0; (j < N) && (getm); j++) {
            for (i = 0; i < N; i++) {
                newst.ball[i][j] = st.ball[i][j];
                newhole[i][j] = hole[i][j];
                if (newst.ball[i][j]) {
                    pos = 0;
                    h = 0;
                    for (l = i-1; l >= 0; l--) {
                        if (newst.ball[l][j]) { pos = l+1; break; }
                        if (wall[l+1][j][l][j]) { pos = l+1; break; }
                        else if (newhole[l][j]) { pos = l; h = newhole[l][j]; break; }
                    }
                    if (h != 0) {
                        if (h != newst.ball[i][j]) { getm = FALSE; break; }
                        else { newhole[pos][j] = newst.ball[i][j] = 0; newst.nball--; }
                    }
                    else if (pos != i) { newst.ball[pos][j] = newst.ball[i][j]; newst.ball[i][j] = 0; }
                }
            }
        }
        if (getm)
            if (cmp_state(&st, &newst)) {
                x = fh(&newst);
                pt = ptaux = hash[x];
                getm = TRUE;
                while (pt != NULL) {
                    if (cmp_state(&(pt->st), &newst) == 0) {
                        if (k > pt->deep) getm = FALSE;
                        else pt->deep = k;
                        break;
                    }
                    ptaux = pt;
                    pt = pt->prox;
                }
                if (getm) {
                    if (pt == NULL) {
                        pt = (statept *) malloc(sizeof(statept));
                        pt->st = newst;
                        pt->deep = k;
                        pt->prox = NULL;
                        if (hash[x] == NULL) hash[x] = pt;
                        else ptaux->prox = pt;
                    }
                    enqueue(q, &newst, newhole, k+1);
                }
            }
            
        /* Move down */
        getm = TRUE;
        newst.nball = st.nball;
        for (j = 0; (j < N) && (getm); j++) {
            for (i = N-1; i >= 0; i--) {
                newst.ball[i][j] = st.ball[i][j];
                newhole[i][j] = hole[i][j];
                if (newst.ball[i][j]) {
                    pos = N-1;
                    h = 0;
                    for (l = i+1; l < N; l++) {
                        if (newst.ball[l][j]) { pos = l-1; break; }
                        else if (wall[l][j][l-1][j]) { pos = l-1; break; }
                        else if (newhole[l][j]) { pos = l; h = newhole[l][j]; break; }
                    }
                    if (h != 0) {
                        if (h != newst.ball[i][j]) { getm = FALSE; break; }
                        else { newhole[pos][j] = newst.ball[i][j] = 0; newst.nball--; }
                    }
                    else if (pos != i) { newst.ball[pos][j] = newst.ball[i][j]; newst.ball[i][j] = 0; }
                }
            }
        }
        if (getm)
            if (cmp_state(&st, &newst)) {
                x = fh(&newst);
                pt = ptaux = hash[x];
                getm = TRUE;
                while (pt != NULL) {
                    if (cmp_state(&(pt->st), &newst) == 0) {
                        if (k > pt->deep) getm = FALSE;
                        else pt->deep = k;
                        break;
                    }
                    ptaux = pt;
                    pt = pt->prox;
                }
                if (getm) {
                    if (pt == NULL) {
                        pt = (statept *) malloc(sizeof(statept));
                        pt->st = newst;
                        pt->deep = k;
                        pt->prox = NULL;
                        if (hash[x] == NULL) hash[x] = pt;
                        else ptaux->prox = pt;
                    }
                    enqueue(q, &newst, newhole, k+1);
                }
            }
            
        /* Move left */
        getm = TRUE;
        newst.nball = st.nball;
        for (i = 0; (i < N) && (getm); i++) {
            for (j = 0; j < N; j++) {
                newst.ball[i][j] = st.ball[i][j];
                newhole[i][j] = hole[i][j];
                if (newst.ball[i][j]) {
                    pos = 0;
                    h = 0;
                    for (l = j-1; l >= 0; l--) {
                        if (newst.ball[i][l]) { pos = l+1; break; }
                        else if (wall[i][l+1][i][l]) { pos = l+1; break; }
                        else if (newhole[i][l]) { pos = l; h = newhole[i][l]; break; }
                    }
                    if (h != 0) {
                        if (h != newst.ball[i][j]) { getm = FALSE; break; }
                        else { newhole[i][pos] = newst.ball[i][j] = 0; newst.nball--; }
                    }
                    else if (pos != j) { newst.ball[i][pos] = newst.ball[i][j]; newst.ball[i][j] = 0; }
                }
            }
        }
        if (getm)
            if (cmp_state(&st, &newst)) {
                x = fh(&newst);
                pt = ptaux = hash[x];
                getm = TRUE;
                while (pt != NULL) {
                    if (cmp_state(&(pt->st), &newst) == 0) {
                        if (k > pt->deep) getm = FALSE;
                        else pt->deep = k;
                        break;
                    }
                    ptaux = pt;
                    pt = pt->prox;
                }
                if (getm) {
                    if (pt == NULL) {
                        pt = (statept *) malloc(sizeof(statept));
                        pt->st = newst;
                        pt->deep = k;
                        pt->prox = NULL;
                        if (hash[x] == NULL) hash[x] = pt;
                        else ptaux->prox = pt;
                    }
                    enqueue(q, &newst, newhole, k+1);
                }
            }
            
        /* Move right */
        getm = TRUE;
        newst.nball = st.nball;
        for (i = 0; (i < N) && (getm); i++) {
            for (j = N-1; j >= 0; j--) {
                newst.ball[i][j] = st.ball[i][j];
                newhole[i][j] = hole[i][j];
                if (newst.ball[i][j]) {
                    pos = N-1;
                    h = 0;
                    for (l = j+1; l < N; l++) {
                        if (newst.ball[i][l]) { pos = l-1; break; }
                        else if (wall[i][l][i][l-1]) { pos = l-1; break; }
                        else if (newhole[i][l]) { pos = l; h = newhole[i][l]; break; }
                    }
                    if (h != 0) {
                        if (h != newst.ball[i][j]) { getm = FALSE; break; }
                        else { newhole[i][pos] = newst.ball[i][j] = 0; newst.nball--; }
                    }
                    else if (pos != j) { newst.ball[i][pos] = newst.ball[i][j]; newst.ball[i][j] = 0; }
                }
            }
        }
        if (getm)
            if (cmp_state(&st, &newst)) {
                x = fh(&newst);
                pt = ptaux = hash[x];
                getm = TRUE;
                while (pt != NULL) {
                    if (cmp_state(&(pt->st), &newst) == 0) {
                        if (k > pt->deep) getm = FALSE;
                        else pt->deep = k;
                        break;
                    }
                    ptaux = pt;
                    pt = pt->prox;
                }
                if (getm) {
                    if (pt == NULL) {
                        pt = (statept *) malloc(sizeof(statept));
                        pt->st = newst;
                        pt->deep = k;
                        pt->prox = NULL;
                        if (hash[x] == NULL) hash[x] = pt;
                        else ptaux->prox = pt;
                    }
                    enqueue(q, &newst, newhole, k+1);
                }
            }
    }
    
    return(INF);
}

int get_int() {

    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}

int main() {

    int x, y, x1, y1;
    int c;
    statept *pt, *ptaux;
    int i, j;

    c = 1;
    while (1) {
        N = get_int(); M = get_int(); W = get_int();
        if ((N == 0) && (M == 0) && (W == 0))
            break;
        impossible = FALSE;
        move = INF;
        
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) {
                st.ball[i][j] = 0;
                hole[i][j] = 0;
                for (x = 0; x < N; x++)
                    for (y = 0; y < N; y++)
                        wall[i][j][x][y] = FALSE;
            }
        st.nball = M;
        
        for (i = 1; i <= M; i++) {
            x = get_int(); y = get_int();
            st.ball[x][y] = i;
        }
        
        for (i = 1; i <= M; i++) {
            x = get_int(); y = get_int();
            if (st.ball[x][y]) {
                if (i != st.ball[x][y])
                    impossible = TRUE;
                else {
                    st.ball[x][y] = 0;
                    st.nball--;
                }
            }
            else
                hole[x][y] = i;
        }
        
        if (st.nball == 0)
            move = 0;
        
        for (i = 0; i < W; i++) {
            x = get_int(); y = get_int(); x1 = get_int(); y1 = get_int();
            wall[x][y][x1][y1] = TRUE;
            wall[x1][y1][x][y] = TRUE;
        }
        
        if (st.nball > 8)
            impossible = TRUE;
        
        if ((!impossible) && (move == INF)) {
            for (i = 0; i < MAXH; i++)
                hash[i] = NULL;
            x = fh(&st);
            hash[x] = (statept *) malloc(sizeof(statept));
            hash[x]->st = st;
            hash[x]->deep = 0;
            hash[x]->prox = NULL;
            q.first = 0;
            q.last = MAXH-1;
            q.c = 0;
            enqueue(&q, &st, hole, 0);
            move = BFS(&q);
        }
        
        printf("Case %d: ", c);
        if (move != INF)
            printf("%d moves\n\n", move);
        else
            printf("impossible\n\n");
        c++;
    }
    
    return 0;
}
