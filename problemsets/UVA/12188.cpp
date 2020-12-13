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
#include <numeric>

using namespace std;

const int MOD = 26;

int main() {
	char S[10000];

	while(1) {
		int C[MOD] = {0};
		int sum;
		int N, q, v;

		scanf("%s", S);
		if (S[0]=='*') break;

		N = strlen(S);
		sum = v = ('a' - S[N-1] + MOD) % MOD;
		C[v]++;

		for (int i = 1; i < N; i++) {
			v = (S[i] - S[i-1] + MOD) % MOD;
			C[v]++;
			sum += v;
		}

		q = sum / MOD;
		int ret = sum;
		int k = MOD-1;
		while(q > 0) {
			if (q > C[k]) {
				ret -= k * C[k];
				q -= C[k];
			}
			else {
				ret -= k * q;
				q = 0;
			}
			k--;
		}

		if (sum % MOD != 0) {
			int aux = 0;
			q = sum/MOD + 1;
			k = 25;
			while(q > 0) {
				if (q > C[k]) {
					aux += (MOD - k) * C[k];
					q -= C[k];
				}
				else {
					aux += (MOD - k) * q;
					q = 0;
				}
				k--;
			}
			if (ret > aux) ret = aux;
		}
		printf("%d\n", ret);

	}

	return 0;
}

