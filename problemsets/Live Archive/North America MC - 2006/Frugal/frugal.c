/* Frugal Search */

#include <stdio.h>
#include <string.h>

char dic[200][50];
int check[200][50];
char query[200];
char q[50][200];
int nq;
int n;


int str_cmp(char *a, char *b) {
    
    return (strcmp(a, b));
}

int satisfy(int num, char *str) {

    int i;
    char v;
    
    v = 0;
    for (i = 0; str[i] != '\0'; ) {
        if (str[i] == '+') { 
            if (check[num][str[i+1]-'a'] == 0) return (0);
            i += 2;
        }
        else if (str[i] == '-') {
            if (check[num][str[i+1]-'a'] != 0) return (0);
            i += 2;
        }
        else {
            if (check[num][str[i]-'a'] != 0) v = 1;
            i++;
        }
    }
    
    if (v) return (1);
    else return (0);
}


int main() {
    
    int i, j;
    char result[50];
    int str_cmp();
    int get;
    
    while (1) {
        n = 0;
        while (1) {
            gets(dic[n]);
            if ((dic[n][0] == '*') || (dic[n][0] == '#')) break;
            n++;
        }
        if (dic[0][0] == '#') break;
        
        qsort(dic, n, sizeof(dic[0]), str_cmp);
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < 50; j++) check[i][j] = 0;
            for (j = 0; dic[i][j] != '\0'; j++) check[i][dic[i][j]-'a'] = 1;
        }
        
        while (1) {
            gets(query);
            if (query[0] == '*') break;
            
            nq = 0; j = 0;
            for (i = 0; query[i] != '\0'; i++) {
                if (query[i] == '|') {
                    q[nq][j] = '\0';
                    j = 0;
                    nq++;
                }
                else q[nq][j++] = query[i];
            }
            q[nq++][j] = '\0';
            
            get = 0;
            for (i = 0; (i < n) && (!get); i++)
                for (j = 0; j < nq; j++) {
                    if (satisfy(i, q[j])) {
                        get = 1;
                        strcpy(result, dic[i]);
                        break;
                    }
                }
            if (get) printf("%s\n", result);
            else printf("NONE\n");
        }
        printf("$\n");
        
    }
    
    return 0;
}
