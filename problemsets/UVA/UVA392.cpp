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
#include <queue>

using namespace std;

int V[10];

int main() {

    while (1) {
        for (int i = 0; i < 9; i++) if (scanf("%d",V+i) == EOF) return 0;
        bool f = false;
        for (int i = 0; i < 9; i++) if (V[i]) {
            if (!f && V[i]<0) putchar('-');
            if (f && V[i]>0) printf(" + ");
            if (f && V[i]<0) printf(" - ");
            if (i==8 || abs(V[i])!=1) printf("%d", abs(V[i]));
            if (i == 7) printf("x");
            else if (i < 8) printf("x^%d", 8-i);
            f = true;
        }
        if (!f) printf("0");
        putchar('\n');
    }

    return 0;
}
