/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<bits/stdc++.h>
using namespace std;
char M[1010][1010];
const int OFF = 100;
int dy[] = {-1,-1,0,1,1};
int dx[] = {-1,1,0,-1,1};
int main(){
	int n; cin >> n;
	for (int i = OFF; i < n+OFF; i++) scanf(" %s ", &M[i][OFF]);
	int r = 0;
	for (int i = OFF; i < n+OFF; i++) for (int j = OFF; j < n+OFF; j++)
		for (int k = 0; k < 5; k++) {
			if (M[i+dy[k]][j+dx[k]]!='X') break;
			if (k == 4) r++;
		}
	cout << r;
}