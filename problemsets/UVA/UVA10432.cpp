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

double R;
int N;

int main() {

    while (scanf("%lf %d", &R, &N) != EOF) {
        double H = cos(M_PI/N) * R;
        double B = sin(M_PI/N) * R;
        double A = B*H*N;
        printf("%.3lf\n", A);
    }

    return 0;
}
