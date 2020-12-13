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
	string a; cin >> a;
	int l = count(a.begin(), a.end(), '1');
	cout << (a[0]=='0'?"0":"1"+string(n-l,'0'));
	
}