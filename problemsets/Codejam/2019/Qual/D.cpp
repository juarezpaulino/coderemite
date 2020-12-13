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
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vector<int> sol;
bool F;

struct tup {
  int l, r;
  int mini, maxi;
  int x;
  int done;
};

int computeStrategy(list<tup> &a, list<tup>::iterator &it) {
  int ret = 0;
  int m = it->r - it->l + 1;
  int mini = it->mini, maxi = it->maxi;
  int l = it->l, r = it->r;
  int x = it->x;
  vector<tup> b;
  if (F) {
    F = 0;
    for (int l1 = l; l1 <= r; l1+=x+1) {
      int r1 = min(l1+x,r);
      b.pb({l1,r1,mini,maxi,-1,0});
      ret++;
    }
  }
  else {
    int m1 = (m+1)/2;
    b.pb({l,l+m1-1,mini,maxi,-1,0});
    b.pb({l+m1,r,mini,maxi,-1,0});
    ret+=2;
  }
  a.insert(next(it),all(b));
  it = a.erase(it);

  return ret;
}

string prepare(list<tup> &a) {
  string ret = "";
  bool one = 0;
  for (auto it = begin(a); it != end(a); ) {
    if (it->done) {
      ret += string(it->r - it->l + 1, (one) ? '1' : '0');
      it++; one ^= 1;
      continue;
    }
    int l = computeStrategy(a, it);
    while (l--) {
      ret += string(it->r - it->l + 1, (one) ? '1' : '0');
      it++; one^=1;
    }  
  }
  return ret;
}

void fetch(list<tup> &a, string &out) {
  bool one = 0;
  int off = 0;
  for (auto it = begin(a); it != end(a); it++) {
    if (it->done) {
      one ^= 1;
      off += it->r - it->l + 1 - it->x;
      continue;
    }
    int l = it->l, r = it->r;
    int m = r-l+1;
    int c = 0;
    for (int i = max(it->mini,off); i <= it->maxi; i++)
      if (out[i]=='0'+one) c++;
      else break;
    it->x = m-c;
    it->mini = off;
    it->maxi = off + c - 1;
    off += c;
    if (it->x == m) {
      for (int i = l; i <= r; i++) sol.pb(i);
      it->done = 1;
    }
    else if (it->x == 0) it->done = 1;
    one ^= 1;
  }
}

void solve() {
  sol.clear(); F = 1;
  int n, b, f; cin >> n >> b >> f;
  list<tup> a;
  a.pb({0,n-1,0,n-1,b,0});
  while (f-- && sol.size() < b) {
    string inp = prepare(a), out;
    cout << inp << endl;
    cin >> out;
    fetch(a, out);
  }
  sort(all(sol));
  for (int i = 0; i < sol.size(); i++) cout << sol[i] << " \n"[i==sol.size()-1];
}

int main() {
  setbuf(stdout, NULL);
 	//cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
    int r; cin >> r;
    if (r == -1) return 0;
  }
}