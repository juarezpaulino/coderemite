/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m; cin>>n>>m;
	for (int i=0;i<n;i++)
		cout<<vector<string>({string(m,'#'),string(m-1,'.')+"#",string(m,'#'),"#"+string(m-1,'.')})[i%4]<<"\n";
}