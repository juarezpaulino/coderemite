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

const double EPS = 1E-6;

struct interval {
    double l, r;
    string s;
};

int N, M;

bool comp(const interval &A, const interval &B) {
    if (A.l != B.l) return A.l < B.l;
    return A.r < B.r;
}

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        vector<interval> S;
        scanf("%d ", &M);
        double l, r;
        char s[1000];
        while (gets(s)) {
            if (!strcmp(s,"0 0")) break;
            sscanf(s, "%lf %lf", &l, &r);
            S.push_back((interval){l,r,string(s)});
        }

        N = S.size();
        sort(S.begin(), S.end(), comp);

        double c = 0, k = 0;
        vector<interval> RET;
        while (c+EPS <= M) {
            interval b; b.r = -1.;
            while (k < N && S[k].r < c) k++;
            while (k < N && S[k].l <= c) {
                if (S[k].r > b.r) b = S[k];
                k++;
            }
            if (b.r == -1) { printf("0\n"); goto OUT; }
            RET.push_back(b);
            c = b.r + EPS;
        }

        printf("%d\n", RET.size());
        for (int i = 0; i < RET.size(); i++) printf("%s\n", RET[i].s.c_str());
OUT:
        if (T) putchar('\n');
    }

    return 0;
}
