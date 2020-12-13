#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLUMNS 12
#define MAX_ROWS 23
#define MAX_NUMBERS 99999999

char eight [MAX_ROWS][MAX_COLUMNS + 1];
char lcddigits [10][MAX_ROWS][MAX_COLUMNS + 1];
char numbers [8];

typedef enum {FALSE,TRUE} boolean;

void buildEight(int size){
    
    int l1,l2;
    for (l1 = 0; l1 < (2 * size) + 3; l1 += size + 1) {
        eight[l1][0] = ' ';
        for (l2 = 1; l2 < size + 1; l2++)
            eight[l1][l2] = '-';
        eight[l1][l2] = ' ';
        eight[l1][size+2] = '\0';
    }
    for (l1 = 1; l1 < (2 * size) + 2; l1++) {
        if (l1 == size+1)
            continue;
        for (l2 = 0; l2 < size+2; l2++)
            if ((l2 == 0) || (l2 == size+1))
                eight[l1][l2] = '|';
            else
                eight[l1][l2] = ' ';
        eight[l1][size+2] = '\0';
    }
}

void buildLcd(int size) {
    
    int l1,l2;
    
    buildEight(size);
    
    for (l1 = 0; l1 < 10; l1++)
        for (l2 = 0; l2 < (size * 2) + 3; l2++)
            strcpy(lcddigits[l1][l2], eight[l2]);
            
    for (l1 = 0; l1 < (size * 2) + 3; l1++) {
        for (l2 = 0; l2 < size + 2; l2++) {
                
            /* 0 */
            if ((l1 == size + 1) && (l2 > 0) && (l2 < size + 1))
                lcddigits[0][l1][l2] = ' ';
                
            /* 1 */
            if (l2 != size + 1)
                lcddigits[1][l1][l2] = ' ';    
            
            /* 2 */
            if (((l1 > 0) && (l1 < size + 1) && (l2 == 0)) || 
            ((l1 > size + 1) && (l1 < (size * 2) + 2) && (l2 == size + 1)))
                lcddigits[2][l1][l2] = ' ';
                
            /* 3 */
            if ((((l1 > 0) && (l1 < size + 1))  || 
            ((l1 > size + 1) && (l1 < (size * 2) + 2))) && (l2 == 0))
                lcddigits[3][l1][l2] = ' ';
                
            /* 4 */
            if ((l1 == 0) || ((l1 > size + 1) && (l2 == 0))
            || (l1 == (size * 2) + 2))
                lcddigits[4][l1][l2] = ' ';
            
            /* 5 */
             if (((l1 > 0) && (l1 < size + 1) && (l2 == size + 1)) || 
            ((l1 > size + 1) && (l1 < (size * 2) + 2) && (l2 == 0)))
                lcddigits[5][l1][l2] = ' ';
                
            /* 6 */
             if ((l1 > 0) && (l1 < size + 1) && (l2 == size + 1))
                lcddigits[6][l1][l2] = ' ';
    
            /* 7 */
            if ((l1 > 0) && (l2 != size + 1))
                lcddigits[7][l1][l2] = ' ';
                
            /* 9 */
             if ((l1 > size + 1) && (l1 < (size * 2) + 2) && (l2 == 0))
                lcddigits[9][l1][l2] = ' ';
        }
    }
            
}

int main (){
    
    int s, l1, l2, num;
    char aux;
    boolean teste;
    
    scanf ("%d ", &s);
    while(s > 0) {
        
        buildLcd(s);
        num = 0;
        teste = FALSE;
        while(scanf("%c", &aux)){
            if (aux == '\n')
                break;
            if (teste == TRUE)
                num = 0;
            teste = FALSE;
            if ((atoi(&aux) == 0) && (num == 0))
                teste = TRUE;
            numbers[num] = atoi(&aux);
            num++;
        }

        for (l1 = 0; l1 < (s * 2) + 3; l1++) {
            for (l2 = 0; l2 < num; l2 ++)
                if (l2 == num-1)
                    printf("%s", lcddigits[numbers[l2]][l1]);
                else
                    printf("%s ", lcddigits[numbers[l2]][l1]);
            putchar('\n');
        }
        
        putchar('\n');
        scanf("%d ",&s);
    }
    return 0;
}
