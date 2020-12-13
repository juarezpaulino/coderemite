/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const double EPS = 1E-10;

int main() {

    char S[10101];
    double t = 0;
    int l = 0, v = 0;
    while (gets(S)) {
        int h, m, s, nv, c;
        c = sscanf(S, "%d:%d:%d %d", &h, &m, &s, &nv);
        int cur = h*3600 + m*60 + s;
        t += (cur-l) / 3600. * v;
        l = cur;
        if (c == 3) printf("%02d:%02d:%02d %.2lf km\n", h, m, s, t+EPS);
        else v = nv;
    }

    return 0;
}
