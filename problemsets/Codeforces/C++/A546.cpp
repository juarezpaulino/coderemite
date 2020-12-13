/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<bits/stdc++.h>
using namespace std;

int main() {
	int k,n,w; cin>>k>>n>>w;
	cout<<max(0,k*(w*w+w)/2-n);
}