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

char S[1000];
int p;
pair<int,int> M[30];
bool error;
int tot;

pair<int,int> expr();

pair<int,int> expr() {
    pair<int,int> A, B, ret;
    if (S[p]>='A' && S[p]<='Z') {
        p++;
        return M[S[p-1]-'A'];
    }
    p++;
    A = expr();
    B = expr();
    if (A.second != B.first) error = true;
    ret = make_pair(A.first, B.second);
    tot += A.first * B.first * B.second;
    p++;
    return ret;
}

int N;

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int r, c;
        scanf("%s %d %d", S, &r, &c);
        M[*S-'A'] = make_pair(r,c);
    }
    while (scanf("%s", S)!=EOF) {
        error = false;
        tot = p = 0;
        expr();
        if (error) puts("error");
        else printf("%d\n", tot);
    }

    return 0;
}
