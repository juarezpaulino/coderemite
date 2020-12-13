/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string R;
vector<string> D;

void go(string ret, int k) {
    if (k == R.size()) { printf("%s\n", ret.c_str()); return; }
    if (R[k]=='0') for (int i = 0; i < 10; i++) go(ret + string(1,'0'+i), k+1);
    else for (int i = 0; i < N; i++) go(ret + D[i], k+1);
}

int main() {

    while (scanf("%d", &N) != EOF) {
        D.clear();
        puts("--");
        char S[1010];
        for (int i = 0; i < N; i++) scanf("%s", S), D.push_back(S);
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            scanf("%s", S);
            R = S;
            go("", 0);
        }
    }

    return 0;
}
