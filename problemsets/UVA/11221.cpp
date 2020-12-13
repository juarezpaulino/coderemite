/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


int main() {

    char S[20202];
    int T;
    scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        gets(S);
        string s;
        for (int i = 0; S[i]; i++)
            if ((S[i]>='a' && S[i]<='z') || ((S[i]>='A' && S[i]<='Z')))
                s += S[i];

        printf("Case #%d:\n", t);
        int K = sqrt(s.size()+1E-10);
        if (K*K != s.size()) { printf("No magic :(\n"); continue; }

        vector<vector<char> > square(K, vector<char>(K,0));
        {
            int i = 0, j = 0;
            for (int k = 0; k < s.size(); k++) {
                square[i][j++] = s[k];
                if (j == K) i++, j = 0;
            }
        }

        bool ok = 1;
        { string t; for (int j = 0; j < K; j++) for (int i = 0; i < K; i++) t += square[i][j]; if (s != t) ok = 0; }
        { string t; for (int j = K-1; j >= 0; j--) for (int i = K-1; i >= 0; i--) t += square[i][j]; if (s != t) ok = 0; }
        { string t; for (int i = K-1; i >= 0; i--) for (int j = K-1; j >= 0; j--) t += square[i][j]; if (s != t) ok = 0; }

        if (!ok) printf("No magic :(\n");
        else printf("%d\n", K);
    }

    return 0;
}
