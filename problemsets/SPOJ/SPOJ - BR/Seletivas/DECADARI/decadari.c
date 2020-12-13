#include <stdio.h>


int main() {
    
    char str[100];
    int h, m, s, c;
    int dh, dm, ds, dc, t;
    double x;
    while (gets(str)) {
        h = (str[0]-'0')*10+(str[1]-'0'); h *= 360000;
        m = (str[2]-'0')*10+(str[3]-'0'); m *= 6000;
        s = (str[4]-'0')*10+(str[5]-'0'); s *= 100;
        c = (str[6]-'0')*10+(str[7]-'0');
        x = h+m+s+c; x *= (10000000. / 8640000.);
        t = x;
        dh = (t / 1000000); t %= 1000000;
        dm = (t / 10000); t %= 10000;
        ds = (t / 100); t %= 100;
        dc = t;
        printf("%d%02d%02d%02d\n", dh, dm, ds, dc);
    }
    
    return 0;
}
