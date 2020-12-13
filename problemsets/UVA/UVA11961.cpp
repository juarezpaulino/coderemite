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
#include <numeric>

using namespace std;

int N, K;

char S[] = "ACGT";
vector<string> RET;
string I;

void go(string A, int k, int d) {
    if (k == N) {
        RET.push_back(A);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (S[i]==I[k]) go(A+string(1,S[i]), k+1, d);
        else if (d+1 <= K) go(A+string(1,S[i]), k+1, d+1);

    }
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        char s[20];
        scanf("%d %d %s", &N, &K, s);
        I = s; RET.clear();
        go("", 0, 0);
        printf("%d\n", RET.size());
        for (int i = 0; i < RET.size(); i++) printf("%s\n", RET[i].c_str());
    }

    return 0;
}
