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

char S, P[100];
int hs, ms, he, me;
const int MOD = 24*60;
double T[3][5] = {
    { 0.1, 0.25, 0.53, 0.87, 1.44 },
    { 0.06, 0.15, 0.33, 0.47, 0.8 },
    { 0.02, 0.05, 0.13, 0.17, 0.3 },
};

int main() {

    while (1) {
        scanf("%c %s %d %d %d %d ", &S, P, &hs, &ms, &he, &me);
        if (S=='#') break;
        double ret;
        int t1 = 0, t2 = 0, t3 = 0;
        int i = hs*60 + ms;
        do {
            if (i >= 8*60 && i < 18*60) t1++;
            else if (i >= 18*60 && i < 22*60) t2++;
            else t3++;
            i = (i+1)%MOD;
        } while (i != he*60 + me);
        int v = S-'A';
        ret = t1*T[0][v] + t2*T[1][v] + t3*T[2][v];
        printf("%10s%6d%6d%6d%3c%8.2lf\n", P, t1, t2, t3, S, ret);
    }

    return 0;
}
