/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int p, l, k, r[100];
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
  cin >> l;
	string a; cin >> a;
	a = "W" + a + "W";
	while ((l = a.find("WB", p)) != -1) 
		r[k++] = (p=a.find("BW", l))-l;
	cout << k << "\n";
	for (l = 0; l < k; l++) cout << r[l] << " ";
}