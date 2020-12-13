/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

char S[30];

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }


int main() {

    while (scanf("%s", S) != EOF) {
        if (*S == '*') break;
        if (*S == 'N') { puts("-1"); continue; }
        int m = 1;
        for (int i = 0; S[i]; i++)
            if (S[i]=='Y') m = lcm(m,i+1);
        bool ok = true;
        for (int i = 0; S[i]; i++)
            if (S[i]=='N' && (m%(i+1)==0)) ok = false;
        if (ok) printf("%d\n", m);
        else puts("-1");
    }

    return 0;
}
