/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "StrongEconomy.cpp"

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


class StrongEconomy {
public:
long long earn(long long n, long long k, long long p, long long t) {
    long long turn = 0, ret = 1123456789123456LL, cur = 0;
    while (1) {
        ll rem = t - cur;
        if (n >= (rem+k-1)/k) { turn++; ret = min(ret, turn); break; }
        if (cur < p) {
            ll need = (rem + n*k-1) / (n*k);
            ret = min(ret, turn + need);
            ll next = (p - cur + n*k-1) / (n*k);
            if (need <= next) break;
            turn += next;
            cur  += next * n*k;
        }
        cur -= p;
        if (n > k) k++;
        else n++;
    }
    return ret;
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 1LL; long long Arg2 = 2LL; long long Arg3 = 10LL; long long Arg4 = 4LL; verify_case(0, Arg4, earn(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 2LL; long long Arg1 = 1LL; long long Arg2 = 2LL; long long Arg3 = 9LL; long long Arg4 = 3LL; verify_case(1, Arg4, earn(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 500000LL; long long Arg3 = 1000002LL; long long Arg4 = 1000001LL; verify_case(2, Arg4, earn(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 5LL; long long Arg1 = 4LL; long long Arg2 = 15LL; long long Arg3 = 100LL; long long Arg4 = 5LL; verify_case(3, Arg4, earn(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

//-
};

//+
int main() {
    StrongEconomy ___test;
    ___test.run_test(-1);
    getchar();
}
//-
