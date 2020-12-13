/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long mergecount (vector<int> &a) {
    long long count = 0;
    int i, j, k, n = a.size();
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

    int N;
    scanf("%d", &N);
    vector<int> A(N,0);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        A[i] = x;
    }
    long long ret = mergecount(A);
    printf("%lld\n", ret);

    return 0;
}
