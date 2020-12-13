/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define SI(A) (A.size())

long long mergecount (vector<int> &a) {
    long long count = 0;
    int i, j, k, n = SI(a);
    if (n <= 1) return 0;
    vector<int> b(a.begin(), a.begin()+n/2);
    vector<int> c(a.begin()+n/2, a.end());
    count += mergecount(b); count += mergecount(c);
    for  (i = j = k = 0 ; i < n; ++i)
        if  (k == c.size()) a[i] = b[j++];
        else if  (j == b.size()) a[i] = c[k++];
        else if  (b[j] <= c[k]) a[i] = b[j++];
        else a[i] = c[k++], count += n/2-j;
    return count;
}


int main() {

    int T, N;
    vector<int> V;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        V.resize(N);
        for (int i = 0; i < N; i++) scanf("%d", &V[i]);
        printf("%lld\n", mergecount(V));
    }

    return 0;
}
