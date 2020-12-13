/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

string b, e;

bool checkb(string &s) {
  int k=s.find('*');
  int l=b.find('*');
  int i = 0, j = 0;
  bool ok = 1;
  while (ok && i<k && j<l) {
    ok&=s[i]==b[j];
    i++; j++;
  }
  if (i < k) b = s.substr(0,k+1);
  return ok;
}

bool checke(string &s) {
  int k=s.rfind('*');
  int l=e.rfind('*');
  int i=s.size()-1, j=e.size()-1;
  bool ok = 1;
  while (ok && i>k && j>l) {
    ok&=s[i]==e[j];
    i--; j--;
  }
  if (i>k) e=s.substr(k);
  return ok;
}

void solve() {
  int n; cin >> n;
  vs a(n);
  for (auto &u:a) cin >> u;
  b = e = "*";
  bool ok = 1;
  string m;
  for (int i=0; ok && i<n; i++) {
    int k=a[i].find('*'), l=a[i].rfind('*');
    if (k!=l) m += a[i].substr(k+1,l-k-1);
    ok&=checkb(a[i]);
    ok&=checke(a[i]);
  }
  b.erase(remove(all(b),'*'),b.end());
  e.erase(remove(all(e),'*'),e.end());
  m.erase(remove(all(m),'*'),m.end());
  if (ok) cout << b+m+e << endl;
  else cout << "*" << endl;
}

int main() {
  //setbuf(stdout, NULL);
 	cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}