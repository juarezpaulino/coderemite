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

vector<int> LIS(vector<int> &A) {
    vector<int> p(A.size());
    vector<int> L;
    int u, v;
	if (A.empty()) return L;
	L.push_back(0);
	for (int i = 1; i < (int)A.size(); i++) {
        // If next element A[i] is greater than last element of current
        // longest subsequence, append this element and continue
        // Change to <= | > | >= to get nondecreasing | decreasing | nonincreasing.
		if (A[L.back()] < A[i]) {
			p[i] = L.back();
			L.push_back(i);
			continue;
		}
        // Find the smallest element referenced by L that is bigger than A[i]
        u = 0, v = L.size()-1;
		while (u < v) {
			int m = (u + v) / 2;
            // Change to <= | > | >= to get nondecreasing | decreasing | nonincreasing.
			if (A[L[m]] < A[i]) u = m+1;
			else v = m;
		}
        // Update L if new value is smaller then previously referenced value
        // Remove if condition to get (non) sequences
        // Change to > to get decreasing.
		if (A[i] < A[L[u]]) {
			if (u > 0) p[i] = L[u-1];
			L[u] = i;
		}
	}
	for (u = L.size(), v = L.back(); u--; v = p[v]) L[u] = v;
	return L;
}

int main() {

    vector<int> A, ret;
    int k;
    while (scanf("%d", &k) != EOF) A.push_back(k);
    ret = LIS(A);
    printf("%d\n-\n", ret.size());
    for (int i = 0; i < ret.size(); i++) printf("%d\n", A[ret[i]]);

    return 0;
}
