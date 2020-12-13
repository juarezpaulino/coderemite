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

int A, B;

int main() {

    while (scanf("%d %d", &A, &B) != EOF) {
        if (A == 1) { printf("[0;%d]\n", B); continue; }
        int k = 0;
        while (A > 1) {
            if (k==0) printf("[%d", A/B);
            else if (k==1) printf(";%d",A/B);
            else printf(",%d",A/B);
            int t = B;
            B = A%B;
            A = t;
            k++;
        }
        printf("]\n");
    }

    return 0;
}
