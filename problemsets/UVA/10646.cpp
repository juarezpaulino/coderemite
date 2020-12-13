/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {

    int T;
    scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        char S[10];
        vector<pair<int,string> > A;
        for (int i = 0; i < 52-25; i++) {
            scanf("%s", S);
            if (S[0]>='2' && S[0]<='9') A.push_back(make_pair(S[0]-'0',S));
            else A.push_back(make_pair(10, S));
        }
        int y = 0;
        for (int k = 0; k < 3; k++) {
            int u = A.back().first;
            y += u;
            for (int i = 0; i < 11-u; i++) A.pop_back();
        }
        for (int i = 0; i < 25; i++) {
            scanf("%s", S);
            if (S[0]>='2' && S[0]<='9') A.push_back(make_pair(S[0]-'0',S));
            else A.push_back(make_pair(10, S));
        }
        printf("Case %d: %s\n", t, A[y-1].second.c_str());
    }

    return 0;
}
