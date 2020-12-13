/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<bits/stdc++.h>
using namespace std;
int n,r,a,b,c;
int main() {
	cin>>n;
	while(n--) cin>>a>>b>>c,r+=(a+b+c)>1;
	cout<<r;
}