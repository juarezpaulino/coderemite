/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "TheNewHouseDivOne.cpp"

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

#define SI(V) (int)(V.size())
#define ALL(M) (M).begin(), (M).end()

////////////////////////////////////////////////////////////////////////////////

class TheNewHouseDivOne {
public:
double distance(vector <int> X, vector <int> Y, int k) {
    double ret = 1E10;
    for (double y = -50.; y <= 50.1; y+=.5)
    for (double x = -50.; x <= 50.1; x+=.5) {
        vector<double> D;
        for (int i = 0; i < SI(X); i++)
            D.push_back(abs(Y[i]-y) + abs(X[i]-x));
        sort(ALL(D));
        ret = min(ret, D[k-1]);
    }
    return ret;
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, -1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 1, -1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 2.0; verify_case(0, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-1, -1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 1, -1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 1.0; verify_case(1, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 4, 4, 4, 4, 3, 3, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7, 4, 4, 5, 6, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; double Arg3 = 1.5; verify_case(2, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {30, -15, 24, -23, 43, -8, -6, -47, 23, -11, 43, 6, -18, 44, -46, 16, 32, 31, 13, 9, 22, 25, 4, -44, 38, -41, -20, 41, -35, 7, 25, 39, -36, -20, -5, -38, -15, -22, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-45, -7, -33, 31, -8, -33, -20, -14, -50, -48, -31, 35, -24, -31, -11, 41, -41, -11, 46, -1, -5, 5, -39, -26, -40, -9, 16, 38, -30, 34, 46, -17, -27, 33, -38, 28, 46, -16, -46}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 13; double Arg3 = 32.0; verify_case(3, Arg3, distance(Arg0, Arg1, Arg2)); }

// END CUT HERE

//-
};

//+
int main() {
    TheNewHouseDivOne ___test;
    ___test.run_test(-1);
    getchar();
}
//-
