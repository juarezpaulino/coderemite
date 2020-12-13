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

int N, M;

int main() {

    while (scanf("%d %d",&N, &M) != EOF) {
        if (N < 2 || M < 2 || M > N) {  printf ("Boring!\n"); continue; }
        bool f = true;
        vector<int> S;
        while (N > 1) {
            if (N%M==0) S.push_back(N);
            else { f = false; break; }
            N /= M;
        }
        S.push_back(1);
        if (!f) printf("Boring!\n");
        else {
            f = 0;
            for (int i = 0; i < S.size(); i++) {
                if (f) putchar(' ');
                f = 1;
                printf("%d", S[i]);
            }
            putchar('\n');
        }
    }

    return 0;
}
