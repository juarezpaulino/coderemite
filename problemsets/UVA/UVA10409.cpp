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

int N;

int D[4][6] = {
    {2,1,4,3,5,0},
    {5,1,0,3,2,4},
    {0,5,1,2,4,3},
    {0,2,3,5,4,1}
};

map<string, int> M;

int main() {

    M["north"] = 0;
    M["south"] = 1;
    M["east"] = 2;
    M["west"] = 3;

    char S[30];
    while (scanf("%d", &N)) {
        if (!N) break;
        int dice[2][6] = {{2,3,1,4,5,6},{}};
        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            int k = M[S];
            for (int i = 0; i < 6; i++) dice[1][i] = dice[0][D[k][i]];
            copy(dice[1], dice[1]+6, dice[0]);
        }
        printf("%d\n", dice[0][2]);
    }

    return 0;
}
