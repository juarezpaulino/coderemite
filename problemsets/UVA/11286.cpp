/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int N;
    while (scanf("%d", &N) && N) {
        vector<vector<int> > B;
        for (int i = 0; i < N; i++) {
            vector<int> A(5,0);
            for (int j = 0; j < 5; j++) scanf("%d", &A[j]);
            sort(A.begin(), A.end());
            B.push_back(A);
        }
        sort(B.begin(), B.end());
        int ret = 0, u = 1, c = 0;
        for (int i = 1; i < B.size(); i++) {
            if (B[i] != B[i-1]) {
                if (u > c) ret = u, c = u;
                else if (u == c) ret += u;
                u = 1;
            }
            else u++;
        }
        if (u > c) ret = u, c = u;
        else if (u == c) ret += u;
        printf("%d\n", ret);
    }

    return 0;
}
