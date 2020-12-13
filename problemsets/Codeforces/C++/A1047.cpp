/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<iostream>
using namespace std;
int main() {
	int n; cin >> n;
	cout << (n==3?"1 1 1":(n-2)%3?"1 1 "+to_string(n-2):"1 2 "+to_string(n-3));
}