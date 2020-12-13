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

long long NUM[20], NUM2[20];
bool V[20], V2[20];
char OP[20];
int N;

int main() {

    int T;
    char S[1000];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", S);
        istringstream is(S);
        N = 0;
        int x;
        char op;
        while (is >> x) {
            NUM[N++] = x;
            if (!(is >> op)) break;
            OP[N] = op;
        }
        copy(NUM, NUM+N, NUM2);
        for (int i = 0; i < N; i++) V[i] = V2[i] = 1;
        for (int i = 1; i < N; i++) {
            if (OP[i]=='+') NUM[i] += NUM[i-1], V[i-1] = 0;
            else NUM2[i] *= NUM2[i-1], V2[i-1] = 0;
        }
        long long maxi = 1, mini = 0;
        for (int i = 0; i < N; i++) {
            if (V[i]) maxi *= NUM[i];
            if (V2[i]) mini += NUM2[i];
        }
        printf("The maximum and minimum are %lld and %lld.\n", maxi, mini);
    }

    return 0;
}
