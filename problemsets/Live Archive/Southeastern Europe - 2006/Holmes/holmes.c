/* Sherlock Homes */

#include <stdio.h>
#include <stdlib.h>

int n, m;
int b[10000][2];


int box_cmp(int *a, int *b) {
    
    return (b[0]-a[0]);    
}

double getp(int s[][2], char *maj) {

    char m1, m2;
    double p1, p2;
    double t = m*n/2;
    
    if (s[0][0] > s[0][1]) { m1 = 'W'; p1 = (double)(s[0][0]*100)/t; }
    else if (s[0][0] < s[0][1]) { m1 = 'B'; p1 = (double)(s[0][1]*100)/t; }
    else return(-1000.0);
    if (s[1][0] > s[1][1]) { m2 = 'W'; p2 = (double)(s[1][0]*100)/t; }
    else if (s[1][0] < s[1][1]) { m2 = 'B'; p2 = (double)(s[1][1]*100)/t; }
    else return(-1000.0);
    
    if (m1 != m2) return (-1000.0);
    
    *maj = m1;
    if (p1 < p2) return (p1);
    else return (p2);
}

int getint() {

    int ch, i, sign = 1;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {
    
    int i, k;
    char odd;
    char maj, maj1, maj2;
    double p, p1, p2;
    int s[2][2];
    int s1[2][2], s2[2][2];
    int end;
    int box_cmp();
    
    while ((n = getint()) != EOF) {
    
        m = getint();
        for (i = 0; i < n; i++) { b[i][0] = getint(); b[i][1] = getint(); }
        
        qsort(b, n, sizeof(int)*2, box_cmp);
        
        if ((n/2)%2) { end = (n/2)-1; odd = 1; }
        else { end = (n/2); odd = 0; }
        s[0][0] = s[0][1] = s[1][0] = s[1][1] = 0; k = 0;
        for (i = 0; i < end; i++) {
            s[k][0] = s[k][0] + b[i][0] + b[n-i-1][0];
            s[k][1] = s[k][1] + b[i][1] + b[n-i-1][1];
            k ^= 1;
        }
        
        /* in odd case, check both choices */
        if (odd) {
            s1[0][0] = s[0][0] + b[i][0]; s1[0][1] = s[0][1] + b[i][1];
            s1[1][0] = s[1][0] + b[n-i-1][0]; s1[1][1] = s[1][1] + b[n-i-1][1];
            s2[0][0] = s[0][0] + b[n-i-1][0]; s2[0][1] = s[0][1] + b[n-i-1][1];
            s2[1][0] = s[1][0] + b[i][0]; s2[1][1] = s[1][1] + b[i][1];
            p1 = getp(s1, &maj1); p2 = getp(s2, &maj2);
            if (p1 > p2) { p = p1; maj = maj1; }
            else { p = p2; maj = maj2; }
        }
        else p = getp(s, &maj);
        
        if (p < 0) printf("No solution\n");
        else printf("%c %.2lf\n", maj, p);
    }
    
    return 0;
}
