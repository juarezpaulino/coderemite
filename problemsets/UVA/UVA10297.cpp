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

int D, V;

int main() {

    while (scanf("%d %d", &D, &V)) {
        if (!(D|V)) break;
        double d = exp(1/3. * log(D*D*D - 6.*V/M_PI));
        printf("%.3lf\n", d);
    }

    return 0;
}
