/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	string s;
	set<string> a;
	while (n--) cin >> s, cout << (a.count(s)?"YES":(a.insert(s),"NO")) << endl;
}