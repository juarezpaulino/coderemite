/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "TheBlackJackDivOne.cpp"

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

int C[15];
char V[] = "0023456789TJQKA";

double go(int s, int N) {
    if (s >= 21) return 0.;
    double ret = 0.;
    for (int i = 0; i < 15; i++) if (C[i]) {
        s += (i == 14) ? 11 : (i > 10) ? 10 : i;
        C[i]--;
        ret += 1./N * (C[i]+1) * (1 + go(s, N-1));
        C[i]++;
        s -= (i == 14) ? 11 : (i > 10) ? 10 : i;
    }
    return ret;
}

class TheBlackJackDivOne {
public:
double expected(vector <string> cards) {
    for (int i = 2; i < 15; i++) C[i] = 4;
    int s = 0;
    FOR(i,0,SI(cards)) {
        int v = 0;
        for (int j = 0; j < 15; j++) if (V[j]==cards[i][0]) {
            v = j; break;
        }
        C[v]--;
        s += (v == 14) ? 11 : (v > 10) ? 10 : v;
    }
    return go(s, 52-cards.size());
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"JS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.105854341736695; verify_case(0, Arg1, expected(Arg0)); }
	void test_case_1() { string Arr0[] = {"KD", "8S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.08; verify_case(1, Arg1, expected(Arg0)); }
	void test_case_2() { string Arr0[] = {"KD", "2S", "2C", "2D", "2H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, expected(Arg0)); }
	void test_case_3() { string Arr0[] = {"AS", "KS", "9S", "JC", "2D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, expected(Arg0)); }

// END CUT HERE

//-
};

//+
int main() {
    TheBlackJackDivOne ___test;
    ___test.run_test(-1);
    getchar();
}
//-
