/* Car Plates Competition */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef double tp;

char sm[10], si[10];
int c;
tp v, mar, isa;
char stm, sti;
tp oldb[7], newb[7];
char val[] = "BDEFGHJKLNOQRSTUVWXYZ";

int main() {
    
    int i, j;
    
    oldb[6] = 1.0; oldb[5] = 10.0; oldb[4] = 100.0; oldb[3] = 1000.0;
    oldb[2] = 10000.0; oldb[1] = 260000.0; oldb[0] = 6760000.0;
    
    newb[6] = 1.0; newb[5] = 10.0; newb[4] = 100.0; newb[3] = 2100.0;
    newb[2] = 44100.0; newb[1] = 926100.0; newb[0] = 19448100.0;
    
    v = 175760000.0;
    
    while (scanf("%s %s %d ", sm, si, &c)) {

        if ((*sm == '*') && (*si == '*') && (c == 0)) break;
        
        if ( ((isdigit(si[3])) && (!isdigit(si[4]))) ||
             ((!isdigit(si[3])) && (isdigit(si[4])))) {
            printf("N\n");
            continue;
        }
        
        if (isdigit(sm[3])) { mar = 0.0; stm = 0; }
        else { mar = v; stm = 1; }
        if (isdigit(si[3])) { isa = 0.0; sti = 0; }
        else { isa = v; sti = 1; }
        
        if (sti) {
            for (i = 0; i < 5; i++)
                if ((si[i] == 'A') || (si[i] == 'C') || (si[i] == 'I')
                 || (si[i] == 'M') || (si[i] == 'P')) break;
            if (i < 5) { printf("N\n"); continue; }
        }
        
        for (i = 0; sm[i] != '\0'; i++)
            if (!stm) {
                if (isdigit(sm[i])) mar += (double)(sm[i]-'0')*oldb[i];
                else mar += (double)(sm[i]-'A')*oldb[i];
            }
            else {
                if (isdigit(sm[i])) mar += (double)(sm[i]-'0')*newb[i];
                else { 
                    for (j = 0; j < 22; j++) if (val[j] == sm[i]) break;
                    mar += (double)j*newb[i];
                }
            }
        for (i = 0; si[i] != '\0'; i++)
            if (!sti) {
                if (isdigit(si[i])) isa += (double)(si[i]-'0')*oldb[i];
                else isa += (double)(si[i]-'A')*oldb[i];
            }
            else {
                if (isdigit(si[i])) isa += (double)(si[i]-'0')*newb[i];
                else { 
                    for (j = 0; j < 22; j++) if (val[j] == si[i]) break;
                    isa += (double)j*newb[i];
                }
            }
            
        if (isa <= mar) { printf("N\n"); continue; }
        
        if (isa-mar > (double)c) { printf("N\n"); continue; }
        
        printf("Y\n");
    }
    
    return 0;
}
