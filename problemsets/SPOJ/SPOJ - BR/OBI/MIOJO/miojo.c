#include <stdio.h>

#define max(a, b) ((a)>(b) ? (a) : (b))

int t, a, b;


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    register int i, n, p, ns, ps, x;

    t = get_int(); a = get_int(); b = get_int();
    for (i = n = p = 0; !n || !p; i++) {
        if (!n) { if (!((t-(b*-i))%a)) { n = 1; x = (t-(b*-i))/a; ns = max(a*x, b*i); } }
        if (!p) { if (!((t-(b*i))%a)) { p = 1; x = (t-(b*i))/a; ps = max(a*x, b*i); } }
    }
    if (ns < ps) printf("%d\n", ns);
    else printf("%d\n", ps);
    
    return 0;
}

