/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <set>


using namespace std;

int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        multiset<int> A, B;
        for (int i = 0; i < N; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            A.insert(a); B.insert(b);
        }
        if (A==B) puts("YES");
        else puts("NO");
    }

    return 0;
}
