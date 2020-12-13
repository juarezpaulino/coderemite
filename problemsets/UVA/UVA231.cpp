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

void LIS(vector<int> &A, vector<int> &L) {
    vector<int> p(A.size());
    int u, v;
	if (A.empty()) return;
	L.push_back(0);
	for (int i = 1; i < (int)A.size(); i++) {
        if (A[L.back()] >= A[i]) {
			p[i] = L.back();
			L.push_back(i);
			continue;
		}
        u = 0, v = L.size()-1;
		while (u < v) {
			int m = (u + v) / 2;
			if (A[L[m]] >= A[i]) u = m+1;
			else v = m;
		}
        if (u > 0) p[i] = L[u-1];
        L[u] = i;
	}
	for (u = L.size(), v = L.back(); u--; v = p[v]) L[u] = v;
}

vector<int> A, L;

int main() {

    int T = 1;
    int x;
    while (1) {
        A.clear(); L.clear();
        if (scanf("%d", &x)==EOF) return 0;
        if (x == -1) break;
        A.push_back(x);
        while (1) {
            if (scanf("%d", &x)==EOF) return 0;
            if (x == -1) break;
            A.push_back(x);
        }
        LIS(A,L);
        if (T > 1) putchar('\n');
        printf("Test #%d:\n", T++);
        printf("  maximum possible interceptions: %d\n", L.size());
    }

    return 0;
}
