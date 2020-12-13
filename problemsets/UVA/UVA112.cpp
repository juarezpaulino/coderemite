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
#include <queue>

using namespace std;

int M;
vector<string> T;
vector<int> P;
bool ret;

void solve(int b, int e, int k) {
    if (b >= e) return;
    if (T[b]=="(") {
        int x = 0;
        if (T[b+1]!="("&&T[b+1]!=")") x = atoi(T[b+1].c_str());
        if (T[b+2]=="("&&T[b+3]==")"&&T[b+4]=="("&&T[b+5]==")") {
            if (k+x==M) ret = true;
            return;
        }
        if (b+2 < T.size()) {
            solve(b+2,P[b+2],k+x);
            if (b+2 != P[e-1]) solve(P[e-1], e-1,k+x);
        }
    }
}

int main() {

    while (scanf("%d", &M) != EOF) {
        T.clear();
        P.clear();
        char S[100];
        vector<char> A;
        string s;
        while (gets(S)) {
            for (int i = 0; S[i]; i++) {
                if (S[i]=='(') { s += " " + string(1,S[i]) + " "; A.push_back(S[i]); }
                else if (S[i]==')') {
                    s += " " + string(1,S[i]) + " ";
                    A.pop_back();
                    if (A.empty()) goto OUT;
                }
                else s += S[i];
            }
        }
OUT:
        istringstream is(s);
        while (is >> s) { T.push_back(s); }
        P.resize(T.size(), -1);
        vector<int> ST;
        for (int i = 0; i < T.size(); i++) {
            if (T[i]=="(") ST.push_back(i);
            else if (T[i]==")") {
                int p = ST[ST.size()-1];
                ST.pop_back();
                P[p] = i; P[i] = p;
            }
        }

        if (T.size()<=2) { puts("no"); continue; }

        ret = false;
        solve(0,T.size()-1,0);
        if (ret) puts("yes");
        else puts("no");
    }

    return 0;
}
