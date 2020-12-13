/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    vector<int> F(45,0);
    F[0] = 1; F[1] = 2;
    for (int i = 2; i < 45; i++) F[i] = F[i-2]+F[i-1];

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);

        vector<pair<int, char> > v(N,pair<int,char>(0,' '));
        for (int i = 0; i < N; i++) scanf("%d ", &v[i].first);

        char S[110];
        gets(S);

        {
            int k = 0;
            for (int i = 0; k < N && S[i]; i++) if (S[i]>='A' && S[i]<='Z') v[k++].second = S[i];
        }

        sort(v.begin(), v.end());

        S[45] = 0;
        int i = 0, k = 0;
        while (k < N && i < 45) {
            while (i < 45 && v[k].first != F[i]) S[i++] = ' ';
            S[i++] = v[k++].second;
        }
        S[i] = 0;
        printf("%s\n", S);
    }

    return 0;
}
