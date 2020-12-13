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
#define on(x) (__builtin_popcount(x))
#define ctz(x) (__builtin_ctz(x))
#define clz(x) (__builtin_clz(x))
#define szb(x) (sizeof(int)*8 - clz(x))

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<double> vd;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int ret[1000][2];

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	set<int> V = {0,50};
	for (int i=1; i <= 20; i++) V.insert(i), V.insert(i<<1), V.insert(i+(i<<1));
	vi v(all(V));

	for (int i=0,x=v[i]; i < sz(v); i++,x=v[i])
		for (int j=i,y=v[j]; j < sz(v); j++,y=v[j])
			for (int k=j,z=v[k]; k < sz(v); k++,z=v[k])
				ret[x+y+z][0]++, ret[x+y+z][1] += (x==y&&y==z)?1:(x==y||y==z)?3:6;
	
	int N;
	while (cin >> N && N > 0) {
		if (ret[N][0]) {
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << N << " IS " << ret[N][0] << "." << endl;
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << N << " IS " << ret[N][1] << "." << endl;
		}
		else cout << "THE SCORE OF " << N << " CANNOT BE MADE WITH THREE DARTS." << endl;
		cout << string(70,'*') << endl;
	}
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}