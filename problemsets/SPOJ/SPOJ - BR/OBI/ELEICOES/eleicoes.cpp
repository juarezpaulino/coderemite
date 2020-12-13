/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <map>

#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()

using namespace std;

map<int, int> voto;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

int main() {
    
    register int i, n, xi;
    
    n = get_int();
    for (i = 0; i < n; i++) { 
        xi = get_int(); if (voto.count(xi)) voto[xi]++; else voto[xi] = 1;
    }
    xi = 0;
    foreach(it, all(voto)) if (it->second > xi) { xi = it->second; n = it->first; }
    
    printf("%d\n", n);
    
    return 0;
}

