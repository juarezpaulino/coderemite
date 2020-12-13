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

vector<int> A, B, P;
int N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        A.resize(N); B.resize(N);
        for (int i = 1; i <= N; i++) A[i-1] = i;
        while (1) {
            scanf("%d", &B[0]);
            if (!B[0]) break;
            for (int i = 1; i < N; i++) scanf("%d", &B[i]);
            int i, j;
            P.clear();
            for (i = j = 0; j < N; ) {
                while (P.size() && B[j]==P.back()) j++, P.pop_back();
                while (i < N && A[i]!=B[j]) P.push_back(A[i]), i++;
                if (i == N) break;
                i++, j++;
            }
            if (j < N) puts("No");
            else puts("Yes");
        }
        putchar('\n');
    }

    return 0;
}
