/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>

using namespace std;

int main() {

	int n; cin >> n;
	cout << "I hate";
	for (int i = 2; i <= n; i++) cout << " that I " << (i%2==0?"love":"hate");
	cout << " it\n";

	return 0;
}