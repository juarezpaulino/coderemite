#include <stdio.h>

#define MAXLINE 100
#define MAXCOLUMN 100

int bombs(int n, int m, int lines, int columns, char matrix[][MAXCOLUMN]) {
    
    int i, j;
    int num = 0;

    for (i = n-1; i <= n+1; i++){
        for (j = m-1; j <= m+1; j++){
            if (((i != n) || (j != m)) && (i >= 0) && (j >= 0) && (i < lines) && 
            (j < columns)) 
                if (matrix[i][j] == '*')
                    num++;
        }
    }
    return(num);
}
        
int main() {
    char mines [MAXLINE][MAXCOLUMN];
    
    int m,n,i,j;
    int cont = 0;
    
    scanf("%d %d ",&n,&m);
    while((n != 0) && (m != 0)) {
        cont++;
        if (cont > 1)
            putchar('\n');
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++)
                scanf("%c",&mines[i][j]);
            getchar();
        }
        
        
        printf("Field #%d:\n", cont);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (mines[i][j] == '*')
                    putchar('*');
                else
                    printf("%d", bombs(i,j,n,m,mines));
            }
            putchar('\n');
        }
                   
    
        scanf("%d %d ",&n,&m);
    }
    
    return 0;
}

