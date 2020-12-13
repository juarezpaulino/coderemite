/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &A, const pair<int, int> &B) {
    if (A.first != B.first) return A.first > B.first;
    return A.second < B.second;
}

int main() {

    char S[1000];

    while (gets(S)) {
        pair<int, int> V[256];
        for (int i = 0; i < 256; i++) V[i].second = i, V[i].first = 0;
        for (int i = 0; S[i]; i++) {
            if (isalpha(S[i])) {
                V[S[i]].first++;
            }
        }
        sort(V, V+256, cmp);
        int f = V[0].first;
        for (int i = 0; i < 256; i++) {
            if (V[i].first != f) break;
            putchar(V[i].second);
        }
        printf(" %d\n", f);
    }

    return 0;
}
