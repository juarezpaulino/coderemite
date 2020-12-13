/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

map<int, int> A;
map<int, int> B;
map<int, int> C;

int main() {

    int x;
    int N = 0;
    while (scanf("%d", &x) != EOF) {
        if (!A.count(x)) A[x] = N, B[N++] = x;
        C[A[x]]++;
    }
    for (map<int, int>::iterator it = B.begin(); it != B.end(); it++) {
        printf("%d %d\n", it->second, C[it->first]);
    }

    return 0;
}
