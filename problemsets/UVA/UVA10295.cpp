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

map<string,int> MAPA;
int M, N;

int main() {

    char S[100];
    int v;
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) scanf("%s %d", S, &v), MAPA[S] = v;
    int T = 0, ret = 0;
    while (T < N) {
        scanf("%s", S);
        if (!strcmp(S,".")) { printf("%d\n", ret); ret = 0; T++; continue;}
        if (MAPA.count(S)) ret += MAPA[S];
    }

    return 0;
}
