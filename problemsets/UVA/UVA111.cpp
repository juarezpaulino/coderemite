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

int N;
int M[30], V[30];

///////////////////////////////////////////////////////////////////////////////
// LIS - O(N*logN)
//
// Input:
// A: Vector to search.
//
// Output:
// L: Longest increasing sequence (only indexes on the original vector)
//
void LIS(vector<int> &A, vector<int> &L) {
    vector<int> p(A.size());
    int u, v;
	if (A.empty()) return;
	L.push_back(0);
	for (int i = 1; i < (int)A.size(); i++) {
        // If next element A[i] is greater than last element of current
        // longest subsequence, append this element and continue
		if (A[L.back()] < A[i]) {
			p[i] = L.back();
			L.push_back(i);
			continue;
		}

        // Find the smallest element referenced by L that is bigger than A[i]
        u = 0, v = L.size()-1;
		while (u < v) {
			int m = (u + v) / 2;
			if (A[L[m]] < A[i]) u = m+1;
			else v = m;
		}

        // Update L if new value is smaller then previously referenced value
		if (A[i] < A[L[u]]) {
			if (u > 0) p[i] = L[u-1];
			L[u] = i;
		}
	}

	for (u = L.size(), v = L.back(); u--; v = p[v]) L[u] = v;

}

int main() {

    int x;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        M[i] = x;
    }

    while (1) {
        for (int i = 0; i < N; i++) {
            if (scanf("%d", &x) == EOF) return 0;
            V[x-1] = M[i];
        }
        vector<int> A(V, V+N), L;
        LIS(A,L);
        printf("%d\n", L.size());
    }

    return 0;
}
