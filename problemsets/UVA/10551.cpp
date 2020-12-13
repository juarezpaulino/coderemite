/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long B, M;
char P[1010];

int main() {

    while (scanf("%lld", &B)) {
        if (!B) break;
        char m[10];
        scanf("%s %s", P, &m);
        M = 0;
        for (int i = 0; m[i]; i++) M = (M*B) + m[i]-'0';
        int k = strlen(P);
        long long mod = P[k-1]-'0', v = 1, u;
        for (int i = k-2; i >= 0; i--) {
            v = (v * B) % M;
            u = ((P[i]-'0') * v) % M;
            mod = (mod + u) % M;
        }
        string ret;
        if (mod == 0) { puts("0"); continue; }
        while (mod) { ret += string(1, '0'+(mod%B)); mod /= B; }
        reverse(ret.begin(), ret.end());
        puts(ret.c_str());
    }

    return 0;
}
