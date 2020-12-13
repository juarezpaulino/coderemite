/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

#define abs(x) ((x)<0?(-x):(x))

char str[100]; int pos;

int get_int() {
    int ch, i, s;
    while ((str[pos] == ' ') || (str[pos] == '\n')) pos++;
    if (str[pos] == '-') { s = 1; pos++; } else s = 0;
    for (i = 0; str[pos]>='0' && str[pos]<='9'; pos++) i = 10*i + (str[pos]-'0');
    if (s) return -i; return i;
}

int gcd(int u, int v) {
	register int t;
	if(u>v) return gcd(v,u);
	while (v!=0) { t=u%v; u=v; v=t; }
	return u;
}


int main() {

    int a1, b1, c1, d1, a2, b2, c2, d2, num, den, n, n2, m, m2, g;

    while (gets(str)) {
        pos = 0; a1 = get_int(); b1 = get_int(); c1 = get_int(); d1 = get_int();
        a2 = get_int(); b2 = get_int(); c2 = get_int(); d2 = get_int();
        if(!(a1 || b1 || c1 || d1 || a2 || b2 || c2 || d2)) return 0;
        num = den = 0;
        if (a1==a2 && b1==b2) {
            if (c1==c2 && d1==d2) den = 1;
            else if (c1 != c2) {
                n = -b1; m = a1; if (m < 0) { n = -n; m = -m; }
                g = gcd(abs(n), m); n /= g; m /= g;
                if (n >= 0) num = n, den = m;
                n = d2-d1; m = c1-c2; if (m < 0) { n = -n; m = -m; }
				n = (n%360 + 360) % 360; g = gcd(abs(n), m); n /= g; m /= g;
				if (den == 0 || n*den < m*num) { num = n; den = m; }
			}
		}
        else if (a1==-a2 && b1==-b2){
			if (c1==c2 && d1==d2) den = 1;
            else if (c1 != c2) {
                n = -b1; m = a1; if (m < 0) { n = -n; m = -m; }
                g = gcd(abs(n), m); n /= g; m /= g;
                if (n >= 0) num = n, den = m;
                n = d2-d1+180; m = c1-c2; if (m < 0) { n = -n; m = -m; }
				n = (n%360 + 360) % 360; g = gcd(abs(n), m); n /= g; m /= g;
				if (!den || n*den < m*num) { num = n; den = m; }
			}
		}
        else{
			if (a1 != a2) {
				n = b2-b1; m = a1-a2; if (m < 0) { n = -n; m = -m; }
                g = gcd(abs(n), m); n /= g; m /= g;
				if (n >= 0) {
					n2 = n*(c1-c2) + m*(d1-d2); m2 = m;
					if (m2 < 0) { n2 = -n2; m2 = -m2; }
                    g = gcd(abs(n2), m2); n2 /= g; m2 /= g;
					if(m2 == 1 && !(n2%360))
						if(!den || n*den < m*num) { num = n; den = m; }
				}
			}
			if (a1 != -a2) {
                n = -b2-b1; m = a1+a2; if (m < 0) { n = -n; m = -m; }
                g = gcd(abs(n), m); n /= g; m /= g;
				if (n >= 0) {
					n2 = n*(c1-c2) + m*(d1-d2); m2 = m;
					if (m2 < 0) { n2 = -n2; m2 = -m2; }
                    g = gcd(abs(n2), m2); n2 /= g; m2 /= g;
					if(m2 == 1 && abs(n2%360)==180)
						if(!den || n*den < m*num) { num = n; den = m; }
				}
			}
		}
		printf("%d %d\n", num, den);
    }

    return 0;
}

