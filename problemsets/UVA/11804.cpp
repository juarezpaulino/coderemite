/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct player {
    string s;
    int a, d;
    bool operator<(const player &B) const {
        if (a != B.a) return a > B.a;
        if (d != B.d) return d < B.d;
        return s < B.s;
    }
};

player P[10];

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        char S[50];
        for (int i = 0; i < 10; i++) scanf("%s %d %d", S, &P[i].a, &P[i].d), P[i].s = S;
        sort(P, P+10);

        vector<string> A, D;
        for (int i = 0; i < 5; i++) A.push_back(P[i].s);
        for (int i = 5; i < 10; i++) D.push_back(P[i].s);
        sort(A.begin(), A.end());
        sort(D.begin(), D.end());
        printf("Case %d:\n", t);
        printf("(%s, %s, %s, %s, %s)\n", A[0].c_str(), A[1].c_str(), A[2].c_str(), A[3].c_str(), A[4].c_str());
        printf("(%s, %s, %s, %s, %s)\n", D[0].c_str(), D[1].c_str(), D[2].c_str(), D[3].c_str(), D[4].c_str());
    }

    return 0;
}
