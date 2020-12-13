#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int n, p, w, d, l;
double pw, pd, pl;
double per;


double arrange(int s, int w, int d, int l) {
    
    int de[50];
    double c, div;
    int i, j;
    
    j = 0;
    for (i = 2; i <= w; i++) de[j++] = i;
    for (i = 2; i <= d; i++) de[j++] = i;
    for (i = 2; i <= l; i++) de[j++] = i;
    
    c = div = 1.0;
    for(i = 2; i <= n; i++) {
        c *= i;
        if (j) div *= de[--j];
        if ((div != 1) && !(fmod(c, div))) { c /= div; div = 1.0; }
    }
    
    return (c);
}


int main() {

    int i, j, k;
    double c;

    while (scanf("%d %d", &n, &p)) {
        
        if (!n && !p) break;    
        
        scanf("%d %d %d", &w, &d, &l);
        pw = w; pw /= (w+d+l);
        pd = d; pd /= (w+d+l);
        pl = l; pl /= (w+d+l);
        
        per = 0.0;
        for (i = 0; i <= n; i++)
            for (j = n-i; j >= 0; j--) {
                if ((3*i)+j < p) break;
                c = 1.0;
                for (k = 0; k < i; k++) c *= pw;
                for (k = 0; k < j; k++) c *= pd;
                for (k = 0; k < n-i-j; k++) c *= pl;
                c *= arrange(n, i, j, n-i-j);
                per += c;
            }
        
        printf("%.1lf\n", per*100.0);
    }

    return 0;
}
