/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> ent;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool search(string a, string b) {
	int k = 0, i = 0;
	while (k < sz(b)) {
		while (i < sz(a) && a[i]!=b[k]) i++;
		if (i == sz(a)) return 0;
		i++; k++;
	}
	return 1;	                        
}

string remove(string a, string b) {
	string ret = "";
	int k = 0, i = 0;
	while (i < sz(a)) {
		while (i < sz(a) && a[i]!=b[k]) ret += a[i++];
		i++; k++;
	}
	return ret;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);
	
	int ord[10] = {0,2,4,1,6,8,3,5,9,7};
	string A[10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
	for (int i = 0; i < 10; i++) sort(all(A[i]));
	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case #" << tt << ": ";
		string S;
		cin >> S; sort(all(S));
		int D[10] = {0};
		for (int i = 0; i < 10; i++) 
			while (search(S,A[ord[i]]))
				S = remove(S,A[ord[i]]), D[ord[i]]++;
		for (int i = 0; i < 10; i++) if (D[i]) cout << string(D[i],i+'0');
		cout << endl;
	}

    return 0;
}