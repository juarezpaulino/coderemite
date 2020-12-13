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
char S[100];
double V[2];

int main() {

    scanf("%d ", &N);
    while (N--) {
        gets(S);
        istringstream is(S);
        int k = 0;
        while (is >> V[k]) k++;
        double ret;
        if (k == 2) ret = 2. * M_PI * V[0] * V[1];
        else ret = M_PI * V[0] * V[0] / 8.;
        printf("%.4lf\n", ret);
    }

    return 0;
}
