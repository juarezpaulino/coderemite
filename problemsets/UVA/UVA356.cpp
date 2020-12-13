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

int main() {

    bool f = false;
    while (scanf("%d", &N) != EOF) {
        if (f) putchar('\n');
        f = true;
        int c = 0, p = 0;
        double r = N - .5;
        r *= r;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            if ((i+1)*(i+1)+(j+1)*(j+1) < r) c++;
            else if (i*i+j*j < r) p++;
        }
        printf("In the case n = %d, %d cells contain segments of the circle.\n", N, p*4);
        printf("There are %d cells completely contained in the circle.\n", c*4);
    }

    return 0;
}
