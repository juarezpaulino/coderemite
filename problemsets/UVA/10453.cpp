/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int DP[1010][1010];
char A[1010];
string r, b;

int solve(int i, int j) {
    int &ret = DP[i][j];
    if (ret != -1) return ret;
    if (i >= j) return ret = 0;
    if (A[i]==A[j]) return ret = solve(i+1, j-1);
    return ret = min(1+solve(i+1,j), 1+solve(i,j-1));
}

void trace(int i, int j) {
    if (i > j) return;
    if (i == j) { r += A[i]; return; }
    if (A[i]==A[j]) { r += A[i]; b.insert(0,1,A[j]); trace(i+1, j-1); return; }
    if (solve(i+1,j) < solve(i, j-1)) { r += A[i]; b.insert(0,1,A[i]); trace(i+1, j); return; }
    r += A[j]; b.insert(0,1,A[j]); trace(i, j-1);
}

int main() {

    while (scanf("%s", A) != EOF) {
        int M = strlen(A);
        memset(DP, -1, sizeof(DP));
        int ret = solve(0,M-1);
        r = "", b = "";
        trace(0,M-1);
        printf("%d %s%s\n", ret, r.c_str(), b.c_str());
    }

    return 0;
}
