/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "MagicalSource.cpp"

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


typedef long long ll;

////////////////////////////////////////////////////////////////////////////////

class MagicalSource {
public:
long long calculate(long long x) {
    ll ret = x, k = 1;
    while (x / k) {
        if (x % k == 0) ret = x / k;
        k *= 10;
        k++;
    }
    return ret;
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1371110974LL; long long Arg1 = 1234LL; verify_case(0, Arg1, calculate(Arg0)); }
	void test_case_1() { long long Arg0 = 111111LL; long long Arg1 = 1LL; verify_case(1, Arg1, calculate(Arg0)); }
	void test_case_2() { long long Arg0 = 10989LL; long long Arg1 = 99LL; verify_case(2, Arg1, calculate(Arg0)); }
	void test_case_3() { long long Arg0 = 120LL; long long Arg1 = 120LL; verify_case(3, Arg1, calculate(Arg0)); }
	void test_case_4() { long long Arg0 = 109999999989LL; long long Arg1 = 99LL; verify_case(4, Arg1, calculate(Arg0)); }

// END CUT HERE

//-
};

//+
int main() {
    MagicalSource ___test;
    ___test.run_test(-1);
    getchar();
}
//-
