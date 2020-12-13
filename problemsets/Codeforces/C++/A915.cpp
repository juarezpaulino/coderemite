/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>

using namespace std;

int main() {

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int n, k, ret = 1000;
	cin >> n >> k;
	while (n--) {
		int x; cin >> x;
		if (k%x==0) ret = min(ret, k/x);
	}
	cout << ret;

	return 0;
}