/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct project {
    string s;
    int v;
    bool operator<(const project &B) const {
        if (v != B.v) return v > B.v;
        return s < B.s;
    }
};

map<string,int> M;
vector<vector<string> > PS;
vector<set<string> > D;
vector<project> P;
char S[1010101];

int main() {

    int k = -1;
    while (gets(S)) {
        if (*S == '0') break;
        if (*S != '1') {
            if (islower(*S)) {
                if (!D[k].count(S)) {
                    D[k].insert(S), M[S]++;
                    PS[k].push_back(S);
                }
            }
            else {
                P.push_back((project){S,0});
                D.push_back(set<string>());
                PS.push_back(vector<string>());
                k++;
            }
            continue;
        }

        for (int i = 0; i < P.size(); i++)
            for (int j = 0; j < PS[i].size(); j++)
                if (M[PS[i][j]] == 1) P[i].v++;

        sort(P.begin(), P.end());
        for (int i = 0; i < P.size(); i++)
            printf("%s %d\n", P[i].s.c_str(), P[i].v);

        D.clear();
        P.clear();
        PS.clear();
        M.clear();

        k = -1;
    }

    return 0;
}
