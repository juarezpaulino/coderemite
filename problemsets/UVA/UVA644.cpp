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

string C[15];
int N;
char S[15];

int main() {

    int T = 1;
    while (1) {
        N = 0;
        while (1) {
            if (scanf("%s", S)==EOF) return 0;
            if (*S=='9') break;
            C[N] = S;
            N++;
        }
        bool ok = true;
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
            if (C[i].size() == C[j].size()) continue;
            string a, b;
            if (C[i].size() < C[j].size()) a = C[i], b = C[j];
            else a = C[j], b = C[i];
            if (b.find(a)==0) { ok = false; goto OUT; }
        }
OUT:
        printf("Set %d is %simmediately decodable\n", T++, (ok) ? "" : "not ");
    }

    return 0;
}
