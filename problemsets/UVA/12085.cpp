/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

void print(int a, int b) {
	if (a == b) { cout << "0" << to_string(a) << endl; return; }
	string A = to_string(a), B = to_string(b), c = "";
	int k; while (A[k] == B[k]) k++;
	c = B.substr(k);
	cout << "0" << A << "-" << c << endl;
}

int main() {

	int N, tt = 1;
	while ((cin >> N) && N) {
		printf("Case %d:\n", tt++);
		int a = 0, b = 0;
		for (int i = 0; i < N; i++) {
			int x; cin >> x;
			if (x != b+1) {
				if (a) print(a, b);
				a = b = x;
			}
			else b = x; 
		}
		if (a) print(a,b);
		cout << endl;
	}
	return 0;
}