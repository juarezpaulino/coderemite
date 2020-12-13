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

int M, N;

int main() {

    char S[10000];
    while (gets(S)) {
        vector<int> A, B;
        {
            istringstream is(S);
            int x;
            while (is >> x) A.push_back(x);
            M = A.size();
        }
        {
            gets(S);
            istringstream is(S);
            int x;
            while (is >> x) B.push_back(x);
            N = B.size();
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int c = 0, i, j;
        for (i = j = 0; i < M && j < N; ) {
            if (A[i] < B[j]) i++;
            else if (B[j] < A[i]) j++;
            else c++, i++, j++;
        }
        if (c==M && c==N) puts("A equals B");
        else if (c==N) puts("B is a proper subset of A");
        else if (c==M) puts("A is a proper subset of B");
        else if (c==0) puts("A and B are disjoint");
        else puts("I'm confused!");
    }

    return 0;
}
