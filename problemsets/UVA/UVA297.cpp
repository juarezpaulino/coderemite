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

int p = 0;

char MAPA[40][40];
char S[500];

void run(char *S, int y, int x, int size) {
    char C = S[p++];
    if (C=='f') {
        for (int i = y; i < y+size; i++) for (int j = x; j < x+size; j++) MAPA[i][j] = 1;
        return;
    }
    else if (C=='e') return;
    for (int i = 0; i < 4; i++) {
        if (i == 0) run(S, y, x+size/2, size/2);
        else if (i == 1) run(S, y, x, size/2);
        else if (i == 2) run(S, y+size/2, x, size/2);
        else run(S, y+size/2, x+size/2, size/2);
    }
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        memset(MAPA,0,sizeof(MAPA));
        scanf("%s", S);
        p = 0;
        run(S, 0, 0, 32);
        scanf("%s", S);
        p = 0;
        run(S, 0, 0, 32);
        int ret = 0;
        for (int i = 0; i < 32; i++) for (int j = 0; j < 32; j++) ret += MAPA[i][j];
        printf("There are %d black pixels.\n", ret);
    }

    return 0;
}
