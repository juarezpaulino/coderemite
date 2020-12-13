/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	int a = count(s.begin(), s.end(), 'A');
	cout << ((a*2 == n) ? "Friendship" : (a*2 > n) ? "Anton" : "Danik");
}