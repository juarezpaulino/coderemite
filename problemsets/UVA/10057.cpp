/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int V[1010101], B[1010101];
int A[65536];

void counting_sort(int *V, int N, int max = 65535) {
    for (int i = 0; i <= max; i++) A[i] = 0;
    for (int i = 0; i < N; i++) A[V[i]]++;
    for (int i = 1; i <= max; i++) A[i] += A[i-1];
    for (int i = N-1; i >= 0; i--) B[--A[V[i]]] = V[i];
}

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return ch;
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    int N;
    while ((N = get_int()) != EOF) {
        int maxi = 0;
        for (int i = 0; i < N; i++) V[i] = get_int(), maxi = max(maxi, V[i]);
        counting_sort(V, N, maxi);
        int x = (N%2) ? B[N/2] : B[(N-1)/2], y = 0, z = (N%2) ? 1 : B[N/2]-B[(N-1)/2]+1;
        for (int i = (N-1)/2; i >= 0 && B[i] == B[(N-1)/2]; i--) y++;
        for (int i = N/2 + (N%2); i < N && B[i] == B[N/2]; i++) y++;
        printf("%d %d %d\n", x, y, z);
    }

    return 0;
}
