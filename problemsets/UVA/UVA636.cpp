/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

char S[100];
map<int, int> R;

int main() {
    for (int i = 1, d; (d = i*i) <= 1000000000 && d >= 0; i++) R[d] = i;

    while (scanf("%s", S)) {
        if (*S=='0') break;
        int b;
        for (b = 2; b < 100; b++) {
            bool ok = true;
            int N = 0;
            for (int i = 0; S[i]; i++) {
                if (S[i]-'0' >= b) ok = false;
                N = (N*b) + S[i]-'0';
            }
            if (ok && R.count(N)) break;
        }
        printf("%d\n", b);
    }

    return 0;
}
