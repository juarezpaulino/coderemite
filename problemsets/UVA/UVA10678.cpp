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

int main() {

    int N, D, L;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d", &D, &L);
        double a = L/2.;
        double b = sqrt(L*L - D*D) / 2.;
        double A = M_PI * a * b;
        printf("%.3lf\n", A);
    }

    return 0;
}
