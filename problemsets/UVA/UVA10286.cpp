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

double F;

int main() {

    while (scanf("%lf", &F) != EOF) {
        printf("%.12lf\n", F * sin(108*M_PI/180) / sin(63*M_PI/180));
    }

    return 0;
}
