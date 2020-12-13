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

int M;

int main() {

    char S[2000];
    while (scanf("%d ", &M) != EOF) {
        vector<int> OX, OY,
                    TX, TY;
        for (int i = 0; i < M; i++) {
            scanf("%s", S);
            for (int j = 0; S[j]; j++)
                if (S[j]=='1') OX.push_back(j), OY.push_back(i);
                else if (S[j]=='3') TX.push_back(j), TY.push_back(i);
        }
        int ret = 0;
        for (int i = 0; i < OX.size(); i++) {
            int t = 0x3F3F3F3F;
            for (int j = 0; j < TX.size(); j++) t = min(t, abs(OX[i]-TX[j]) + abs(OY[i]-TY[j]));
            if (t > ret) ret = t;
        }
        printf("%d\n", ret);
    }

    return 0;
}
