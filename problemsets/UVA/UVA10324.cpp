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

char S[1000010];
int C[1000010];

int main() {

    int T = 1;
    while (gets(S)) {
        int N = strlen(S);
        memset(C,0,sizeof(int)*N);
        for (int i = 1; S[i]; i++) {
            C[i] = C[i-1];
            if (S[i]!=S[i-1]) C[i]++;
        }
        scanf("%d ", &N);
        printf("Case %d:\n", T++);
        while (N--) {
            int i, j;
            scanf("%d %d ", &i, &j);
            if (C[i]!=C[j]) puts("No");
            else puts("Yes");
        }
    }

    return 0;
}
