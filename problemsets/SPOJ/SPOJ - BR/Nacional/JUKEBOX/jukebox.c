/* Jukebox */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINT 1000
#define newline() while(getchar() != '\n');

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    char s[31], a[31];
    int ls, la;
} music;

int min;                /* Menor soma golden string. */

int n;                  /* Number of songs. */

char art[6][31];        /* Artistas. */
int lart[6];
int nart;
int fart[6];            /* Frequencia do artista. */

bool subset[6];         /* Dominio backtracking - artistas validos */

char str[1100][31];     /* Candidatos a golden string. */
int nstr;
int freq[1100];
int parent[1100];       /* musica pai. */
bool type[1100];        /* Deriva de song(0) ou artist(1). */

music m[30];            /* Playlist. */


void add_str(int k, char *s, int p, int t) {

    int i, j;
    
    for (i = 0; i < nstr; i++) {
        for (j = 0; j < k; j++)
            if (s[j] != str[i][j])
                break;
        if (j == k)
            break;
    }
    if (i == nstr) {
        for (j = 0; j < k; j++) str[nstr][j] = s[j];
        freq[nstr] = 1;
        parent[nstr] = p;
        type[nstr++] = t;
    }
    else {
        if ((parent[i] != p) || (type[i] != t)) {    
            freq[i]++;
            parent[nstr] = p;   
        }
    }
}

int golden() {

    int k;
    int s;
    int sum;
    char *sub;
    int f[6];
    int back[6];
    bool notfound[1100];
    int i, j, l;
    
    for (i = 0; i < nart; i++) {
        f[i] = fart[i];
        back[i] = MAXINT;
    }
    
    for (i = 0; i < n; i++)
            notfound[i] = TRUE;
            
    sum = s = 0;
    for (k = 1; k <= 30; k++) {
        /* Distancia - otimizacao */
        if ((n-s)*k+sum > min) return (MAXINT);    
        
        /* Contagem de frequencias. */
        nstr = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j <= m[i].ls - k; j++) {
                sub = &m[i].s[j];
                add_str(k, sub, i, 0);
            }
        for (i = 0; i < nart; i++)
            if (subset[i])
                for (j = 0; j <= lart[i] - k; j++) {
                    sub = &art[i][j];
                    add_str(k, sub, i, 1);
                }

        /* Localiza golden strings. */
        for (i = 0; i < nstr; i++)
            if (freq[i] == 1) {
                if (type[i] == 0) {
                    if (notfound[parent[i]]) {
                        sum += k;
                        s++;
                        notfound[parent[i]] = FALSE;
                        for (j = 0; j < nart; j++) 
                            if (!strcmp(art[j], m[parent[i]].a)) break;
                        if ((subset[j]) && (f[j] > 0)) {
                            f[j]--;
                            if (f[j] == 1)
                                if (back[j] < MAXINT) {
                                    f[j]--;    
                                    for (l = 0; l < n; l++)
                                        if ((notfound[l]) && (!strcmp(art[j], m[l].a)))
                                            break;
                                    sum += back[j];
                                    s++;
                                    notfound[l] = FALSE;
                                }
                        }
                    }
                }
                else {
                    if (f[parent[i]] == 1) {
                        f[parent[i]]--;
                        for (j = 0; j < n; j++) 
                            if ((notfound[j]) && (!strcmp(art[parent[i]], m[j].a))) break;
                        sum += k;
                        s++;
                        notfound[j] = FALSE;
                    }
                    else if (f[parent[i]] > 1) {
                        if (back[parent[i]] == MAXINT)
                            back[parent[i]] = k;
                    }
                }
            }
        if (s == n)
            break;
    }
    if (s == n)
        return (sum);
    else
        return (MAXINT);
}

void backtrack(int k) {

    int sum;
    int d;
    int i;

    if (k <= nart) {
        sum = golden();
        if (sum < min)
            min = sum;
        if (subset[nart-1] == FALSE) {
            for (d = nart-1; (subset[d] == FALSE) && (d >= 0); d--);
            for (i = d+1; i < nart; i++) {
                subset[i] = TRUE;
                backtrack(k+1);
                subset[i] = FALSE;
            }
        }
    }
}


int main() {
    
    int i, j;
    char ch;
    
    while (scanf("%d", &n)) {
        if (!n) break;   
        
        newline();
        nart = 0;
        for (i = 0; i < n; i++) {
            m[i].ls = 0;
            while ((ch = getchar()) != '\n') m[i].s[m[i].ls++] = ch;
            m[i].s[m[i].ls] = '\0';
            m[i].la = 0;
            while ((ch = getchar()) != '\n') m[i].a[m[i].la++] = ch;
            m[i].a[m[i].la] = '\0';
            for (j = 0; j < nart; j++)
                if (strcmp(art[j], m[i].a) == 0)
                    break;
            if (j == nart) {
                strcpy(art[nart], m[i].a);
                lart[nart] = m[i].la;
                fart[nart++] = 1;
            }
            else
                fart[j]++;
        }
        
        min = MAXINT;
        for (i = 0; i < nart; i++)
            subset[i] = FALSE;        
        backtrack(0);
        
        printf("%d\n", min);
    }
    
    return 0;
}
