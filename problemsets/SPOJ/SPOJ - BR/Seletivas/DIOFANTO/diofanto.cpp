/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <map>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Teorema de Bezout
//

////////////////////////////////////////////////////////////////////////////////
// Determina a e b tais que a / x + b / y == gcd(x, y).
//
typedef pair<int, int> bezout;

bezout find_bezout(int x, int y) {
    if (y == 0) return bezout(1, 0);
    bezout u = find_bezout(y, x % y);
    return bezout(u.second, u.first - (x/y) * u.second);
}

////////////////////////////////////////////////////////////////////////////////
// Acha a menor solução não-negativa de a/x = b (mod m).
// Retorna -1 se a congruência for impossível.
//
int mod(int x, int m) { return x % m + ((x < 0) ? m : 0); }

int solve_mod(int a, int b, int m) {
    if (m < 0) return solve_mod(a, b, -m);
    if (a < 0 || a >= m || b < 0 || b >= m)
        return solve_mod(mod(a, m), mod(b, m), m);
    bezout t = find_bezout(a, m);
    int d = t.first * a + t.second * m;
    if (b % d) return -1;
    else return mod(t.first * (b / d), m);
}


////////////////////////////////////////////////////////////////////////////////
// Numero de solucoes: x1+x2+...+xn = C -> (n+C-1)!/(C!*(n-1)!)

int diofanto(int n, int c) {
    int k = (n-1 > c) ? n-1 : c;
    int e = 1, d = 1;
    int i, j;
    for (j = 1, i = k+1; i <= n+c-1; i++, j++) {
        e = (e*i)%1300031; d = (d*j)%1300031;
    }
    return (e*solve_mod(d, 1, 1300031))%1300031;
}

int main() {
    
    int n, c, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &c);
        printf("%d\n", diofanto(n, c));
    }
    return 0;
}
