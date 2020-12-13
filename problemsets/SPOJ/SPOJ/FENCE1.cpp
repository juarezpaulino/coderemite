/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

const double PI = acos(-1);

int main() {

    int L;
    while (cin >> L) {
        if (L == 0) break;
        double ret = L*L;
        ret /= 2.*PI;
        printf("%.2lf\n", ret);
    }

    return 0;
}
