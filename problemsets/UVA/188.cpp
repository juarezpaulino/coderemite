/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    char S[1010];
    while (gets(S)) {
        istringstream is(S);
        string s;
        vector<int> V;
        long long C = 1000000000;
        while (is >> s) {
            int v = 0;
            for (int i = 0; i < s.size(); i++) v = (v<<5) + s[i]-'a'+1;
            V.push_back(v);
            if (v < C) C = v;
        }
        puts(S);
        int N = V.size();
        while (1) {
            long long B = -1;
            for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++)
                if ((C/V[i])%N == (C/V[j])%N)
                    B = max(B, min(((C/V[i])+1)*V[i],((C/V[j])+1)*V[j]));
            if (B == -1) break;
            C = B;
        }
        printf("%lld\n\n", C);
    }

    return 0;
}
