/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "UnfoldingTriangles.cpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define SI(V) (int)(V.size())
#define ALL(M) (M).begin(), (M).end()
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define UNIQUE(v) sort(ALL(v)),(v).resize(unique(ALL(v))-(v).begin())

const int INF = 0x3F3F3F3F;
const double EPS = 1E-9;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////////////////////////////////////////////////////////////

class UnfoldingTriangles {
public:
int solve(vector <string> grid, int unfoldLimit) {
    int M = SI(grid);
    int N = SI(grid[0]);
    int ret = -1;
    FOR(i,0,M) FOR(j,0,N) FOR(k,1,min(M,N)+1) {
        int y1 = i;
        int x1 = j;
        int y2 = i-k+1;
        int x2 = j+k-1;
        if (y2 < 0 || x2 >= N) continue;
        bool ok = 1;
        for (int l = 0; l < k; l++) if (grid[y1-l][x1+l]!='/') ok = 0;
        int c = 0;
        for (int l = 0; l < k; l++) for (int n = x1+l+1; n <= x2; n++) {
            if (grid[y1-l][n]=='/') c++;
            if (grid[y1-l][n]=='.') ok = 0;
        }
        if (c > unfoldLimit) continue;
        if (x2+1 < N) for (int m = y1; m >= y2; m--) if (grid[m][x2+1]=='#') ok = 0;
        if (y1+1 < M) for (int n = x1; n <= x2; n++) if (grid[y1+1][n]=='#') ok = 0;
        if (ok) ret = max(ret, k*(k+1)/2);
    }
    return ret;
}

//+

// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {".../",
 "../#",
 "./#/",
 "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 10; verify_case(0, Arg2, solve(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {".../",
 "../#",
 "./#/",
 "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, solve(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"////",
 "////",
 "////",
 "////"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(2, Arg2, solve(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {".....#...",
 "....###.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = -1; verify_case(3, Arg2, solve(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"#//#",
 "#//#",
 "####",
 "///#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; verify_case(4, Arg2, solve(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {".../.../",
 "../#..//",
 "./.#.///",
 "/###...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(5, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

//-
};

//+
int main() {
    UnfoldingTriangles ___test;
    ___test.run_test(-1);
    getchar();
}
//-
