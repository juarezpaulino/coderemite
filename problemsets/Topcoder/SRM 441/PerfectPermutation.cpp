/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "PerfectPermutation.cpp"

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

class PerfectPermutation {
public:
int reorder(vector <int> P) {
    int U[100] = {0};
    int c = 0;
    FOR(i,0,SI(P)) if (!U[i]) {
        int p = i;
        while (!U[p]) {
            U[p] = 1;
            p = P[p];
        }
        c++;
    }
    return c == 1 ? 0 : c;
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, reorder(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 0, 1, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, reorder(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, reorder(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 5, 3, 2, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, reorder(Arg0)); }
	void test_case_4() { int Arr0[] = {4, 2, 6, 0, 3, 5, 9, 7, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, reorder(Arg0)); }

// END CUT HERE

//-
};

//+
int main() {
    PerfectPermutation ___test;
    ___test.run_test(-1);
    getchar();
}
//-
