/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "MaxTriangle.cpp"

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
const double EPS = 1E-9;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////////////////////////////////////////////////////////////

vector<pair<int,int> > find_solution(int A) {
    vector<pair<int,int> > ret;
    for (int i = 0; i*i <= A; i++) {
        int j = A-i*i;
        int k = sqrt(j)+EPS;
        if (k*k==j) {
            ret.push_back(make_pair(i,k));
            ret.push_back(make_pair(i,-k));
            ret.push_back(make_pair(-i,k));
            ret.push_back(make_pair(-i,-k));
        }
    }
    return ret;
}

class MaxTriangle {
public:
double calculateArea(int A, int B) {
    double ret = -1;
    vector<pair<int,int> > VA = find_solution(A),
                           VB = find_solution(B);
    FOR(i,0,SI(VA)) FOR(j,0,SI(VB)) {
        double area = fabs(VA[i].first * VB[j].second - VA[i].second*VB[j].first) / 2.;
        if (cmp(area)>0) ret = max(ret, area);
    }
    return ret;
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 0.5; verify_case(0, Arg2, calculateArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 7; double Arg2 = -1.0; verify_case(1, Arg2, calculateArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 41; int Arg1 = 85; double Arg2 = 29.5; verify_case(2, Arg2, calculateArea(Arg0, Arg1)); }

// END CUT HERE

//-
};

//+
int main() {
    MaxTriangle ___test;
    ___test.run_test(-1);
    getchar();
}
//-
