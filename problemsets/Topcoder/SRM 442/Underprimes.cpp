/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "Underprimes.cpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

////////////////////////////////////////////////////////////////////////////////


class Underprimes {
public:
int howMany(int A, int B) {
    vector<int> under_prime(B+1, 0);
    under_prime[0] = under_prime[1] = 1;
    for (int k = 2; k <= B; k++) if (under_prime[k]==0) {
        for (int i = 2*k; i <= B; i += k) {
            for (int x = i; x%k==0; x/=k) under_prime[i]++;
        }
    }
    int ret = 0;
    for (int i = A; i <= B; i++) if (under_prime[under_prime[i]]==0) ret++;
    return ret;
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 5; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 105; int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 217; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

//-
};

//+
int main() {
    Underprimes ___test;
    ___test.run_test(-1);
    getchar();
}
//-
