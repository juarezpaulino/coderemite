/* Network */

#include <stdio.h>
#include <stdlib.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXINT 1000000000

typedef struct {
    int byte;
    int msg;
    int num;
} pack;

typedef struct {
    int st;
    int org;
} ord;


int N, M;

pack pk[1001];
int npk[6];

ord ordem[6][1001];

int b[6][1001];

int min;

int dominio[6];


int pk_cmp(ord *a, ord *b) {
    
    return(a->st-b->st);
}

int network() {
    
    int msg, num;
    int kd;
    bool inbuf[6][1001];
    int buf;
    int emp;
    int i, j;
    
    for (i = 1; i <= N; i++)
        for (j = 1; j <= npk[i]; j++)
            inbuf[i][j] = FALSE;
    
    kd = 0;
    msg = dominio[kd];
    num = 1;
    buf = emp = 0;
    for (i = 0; i < M; i++) {
        if ((pk[i].num == num) && (pk[i].msg == msg)) {
            num++;
            if (num > npk[pk[i].msg]) {
                kd++;
                if (kd > N)
                    return (buf);
                msg = dominio[kd];
                num = 1;
            }
            while (inbuf[msg][num]) {
                emp += b[msg][num];
                num++;
                if (num > npk[pk[i].msg]) {
                    kd++;
                    if (kd > N)
                        return (buf);
                    msg = dominio[kd];
                    num = 1;
                }
            }
        }
        else {
            if (emp) {
                emp -= pk[i].byte;
                if (emp < 0) {
                    buf += -(emp);
                    emp = 0;
                }
            }
            else 
                buf += pk[i].byte;
            inbuf[pk[i].msg][pk[i].num] = TRUE;
            if (buf >= min)
                return(MAXINT);
        }   
    }
    
    return (buf);
}

void backtrack(int k) {
    
    int i;
    int net;
    bool inperm[6];
    
    if (k == N) {
        net = network();
        if (net < min)
            min = net;
        return;    
    }
    
    for (i = 1; i <= N; i++) inperm[i] = FALSE;
    for (i = 0; i < k; i++) inperm[dominio[i]] = TRUE;
    
    for (i = 1; i <= N; i++)
        if (!inperm[i]) {
            dominio[k] = i;
            backtrack(k+1);
        } 
}


int main() {
    
    int i, j;
    int st, end, msg;
    int c;
    int pk_cmp();
    
    c = 1;
    while (scanf("%d %d", &N, &M)) {
        
        if ((N == 0) && (M == 0))
            break;
        
        for (i = 1; i <= N; i++)
            npk[i] = 0;
        
        while (getchar() != '\n');
        while (getchar() != '\n');
        for (i = 0; i < M; i++) {
            scanf("%d %d %d", &msg, &st, &end);
            pk[i].msg = msg;
            pk[i].byte = end-st+1;
            ordem[msg][npk[msg]].st = st;
            ordem[msg][npk[msg]++].org = i;
        }
        for (i = 1; i <= N; i++) {
            qsort(ordem[i], npk[i], sizeof(ord), pk_cmp);
            for (j = 0; j < npk[i]; j++) {
                pk[ordem[i][j].org].num = j+1;
                b[i][j+1] = pk[ordem[i][j].org].byte;
            }
        }
        
        min = MAXINT;
        backtrack(0);
        
        printf("Case %d: %d\n\n", c, min);
        c++;
    }
    
    return 0;
}
