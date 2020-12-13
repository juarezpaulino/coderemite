/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {

	int k, m;
	while (cin >> k >> m) {
		if (k == m) { cout << k << " " << m << " " << "12:00" << endl; continue; }
		int n = 6 * abs(k-m);
		int t = (4320 * (86400 - k) + n/2) / n;
		t %= 60*12;
		printf("%d %d %02d:%02d\n", k, m, t<60?12:t/60, t%60);
	}

	return 0;
}