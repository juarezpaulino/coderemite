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

string D[100];
vector<int> C[100];

vector<int> code(string A) {
    vector<int> ret(26,0);
    for (int i = 0; i < A.size(); i++) ret[A[i]-'a']++;
    return ret;
}

int main() {

    int N = 0;
    char S[100];
    while (scanf("%s", S)) {
        if (*S == 'X') break;
        D[N] = S;
        N++;
    }
    sort(D, D+N);
    for (int i = 0; i < N; i++) C[i] = code(D[i]);
    while (scanf("%s", S)) {
        if (*S == 'X') break;
        vector<int> c = code(S);
        bool f = false;
        for (int i = 0; i < N; i++) if (c == C[i]) {
            printf("%s\n", D[i].c_str());
            f = true;
        }
        if (!f) puts("NOT A VALID WORD");
        puts("******");
    }

    return 0;
}
