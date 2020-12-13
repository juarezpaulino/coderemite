/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "IncredibleMachine.cpp"

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


////////////////////////////////////////////////////////////////////////////////

class IncredibleMachine {
public:
double gravitationalAcceleration(vector <int> x, vector <int> y, int T) {
    double v0 = 0, a, t = 0.;
    FOR(i,1,SI(x)) {
        double dx = abs(x[i]-x[i-1]);
        double dy = abs(y[i]-y[i-1]);
        double d = sqrt(dx*dx + dy*dy);
        a = dy / d;
        double ti = (-v0 + sqrt(v0*v0 + 2*a*d)) / a;
        t += ti;
        v0 = v0 + a*ti;
    }
    return t/T*t/T;
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 9.807692307692307; verify_case(0, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,26,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,26,24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 26.743031720603582; verify_case(1, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,6,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 1.1076837407708007; verify_case(2, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }

// END CUT HERE

//-
};

//+
int main() {
    IncredibleMachine ___test;
    ___test.run_test(-1);
    getchar();
}
//-
