/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int main() {

	int N, tt = 1;
	while ((cin >> N) && N) {
		printf("Case %d:\n", tt++);
		int A, B = 0, C = N;
		string a, b, c;
		bool p = 1;
		for (int i = 0; i < N; i++) cin >> A, B+=A;
		if (B < 0) p = 0, B = -B;
		A = __gcd(B,C);
		B /= A; C /= A;
		A = B/C; B -= A*C;
		a = to_string(A); b = to_string(B); c = to_string(C);
		if (C != 1) {
			cout << (p?"":"  ") << (A!=0?string(a.size(),' '):"") << setw(c.size()) << B << endl;
			cout << (p?"":"- ") << (A!=0?a:"") << string(c.size(), '-') << endl;
			cout << (p?"":"  ") << (A!=0?string(a.size(),' '):"") << C << endl;
		}
		else {
			cout << (p?"":"- ") << A << endl;
		}
	}
	                                       
	return 0;
}