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

double A, B;
char OP;
char U[10000], V[10000];

const double MAX = 0x7FFFFFFF;

int main() {

    while (scanf("%s %c %s", U, &OP, V) != EOF) {
        A = atof(U);
        B = atof(V);
        printf("%s %c %s\n", U, OP, V);
        if (A > MAX) printf("first number too big\n");
        if (B > MAX) printf("second number too big\n");
        if ((OP=='+' && A+B > MAX) || (OP=='*' && A*B > MAX)) printf("result too big\n");
    }

    return 0;
}
