#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int st, end;
    char found; 
} indice;

int n, m;

indice ind[10000];
char emoticon[110][20];
int size[110];

int cmp(indice *a, indice *b) {
    if (a->st != b->st)
        return (a->st-b->st);
    return (b->end-a->end);
}


int main() {
	
	int i, j, k;
	char str[110];
	int ne, nind;
	char *pt, *straux;
	int taps;
	int cmp();

	
	while (scanf("%d %d ", &n, &m)) {
		
		if (!n && !m) break;
	
		/* Realiza leitura e elmina continencias. */
		ne = 0;
		for (i = 0; i < n; i++) {
			gets(str);
			size[ne] = strlen(str);
			for (j = 0; j < ne; j++) {
				if (size[ne] < size[j]) {
					pt = strstr(emoticon[j], str);
					if (pt) size[j] = -1;
				}
				else {
					pt = strstr(str, emoticon[j]);
					if (pt) break;
				}
			}
			if (j == ne) { strcpy(emoticon[ne], str); ne++; }
		}
		
		taps = 0;
		for (i = 0; i < m; i++) {
			gets(str);
			nind = 0;
			for (j = 0; j < ne; j++) {
                if (size[j] == -1) continue;
                straux = str;
                while (1) {
                    pt = strstr(straux, emoticon[j]);
                    if (!pt) break;
                    ind[nind].st = pt-str; ind[nind].end = ind[nind].st+size[j]-1;
                    ind[nind].found = 0;
                    nind++;
                    straux = pt+1;
                }
            }
            
            qsort(ind, nind, sizeof(indice), cmp);
            
            for (j = 0; j < nind; j++) {
                if (ind[j].found) continue;
                for (k = j+1; k < nind; k++)
                    if (ind[k].st <= ind[j].end) 
                        ind[k].found = 1;
                taps++;
            }
		}
		
		printf("%d\n", taps);
	}
	
	return 0;
}
