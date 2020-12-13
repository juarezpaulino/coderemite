/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main() {

    char S[111];
    int T;
    scanf("%d", &T);
    int id = 1;
    while (T--) {
        int N, x;
        map<string, int> mapa;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s %d", S, &x);
            mapa[S] = x;
        }
        scanf("%d %s", &x, S);
        printf("Case %d: ", id++);
        if (!mapa.count(S) || mapa[S] > x+5) puts("Do your own homework!");
        else if (mapa[S] > x) puts("Late");
        else puts("Yesss");
    }

    return 0;
}
