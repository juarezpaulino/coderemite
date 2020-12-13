/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    char a[1010], b[1010];
    int id = 1;
    while (gets(a) && gets(b)) {
        vector<string> A, B;
        for (int k = 0; a[k]; ) {
            while (a[k] && !isalnum(a[k])) k++;
            if (!a[k]) break;
            string s;
            while (a[k] && isalnum(a[k])) s += a[k++];
            A.push_back(s);
        }
        for (int k = 0; b[k]; ) {
            while (b[k] && !isalnum(b[k])) k++;
            if (!b[k]) break;
            string s;
            while (b[k] && isalnum(b[k])) s += b[k++];
            B.push_back(s);
        }
        printf("%2d. ", id++);
        if (!A.size() || !B.size()) { puts("Blank!"); continue; }
        int DP[500][500] = {0};
        for (int i = 1; i <= A.size(); i++) for (int j = 1; j <= B.size(); j++) {
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            if (A[i-1]==B[j-1]) DP[i][j] = max(DP[i][j], DP[i-1][j-1]+1);
        }
        printf("Length of longest match: %d\n", DP[A.size()][B.size()]);
    }

    return 0;
}
