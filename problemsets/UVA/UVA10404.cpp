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

int N, M;
int V[20];
int DP[1234567];
int id = 1;

int main() {

    while (scanf("%d %d", &N, &M)!=EOF) {
        for (int i = 0; i < M; i++) scanf("%d", V+i);
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                int x = i-V[j];
                if (x >= 0 && DP[x]!=id) DP[i] = id;
            }
        }
        if (DP[N]==id) puts("Stan wins");
        else puts("Ollie wins");
        id++;
    }

    return 0;
}
