/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "CubeWalking.cpp"

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

char MAPA[3][4] = {"RBR","BGB","RBR"};
map<char,string> name;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

class CubeWalking {
public:
string finalPosition(string mov) {
    name['R'] = "RED";
    name['B'] = "BLUE";
    name['G'] = "GREEN";
    int d = 0;
    int py = 1, px = 1;
    FOR(i,0,SI(mov)) {
        if (mov[i]=='W') {
            py = (py+dy[d]+3)%3;
            px = (px+dx[d]+3)%3;
        }
        else if (mov[i]=='L') d = (d+1)%4;
        else d = (d+3)%4;
    }
    return name[MAPA[py][px]];
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLRR"; string Arg1 = "GREEN"; verify_case(0, Arg1, finalPosition(Arg0)); }
	void test_case_1() { string Arg0 = "WWWWWWWWWWWW"; string Arg1 = "GREEN"; verify_case(1, Arg1, finalPosition(Arg0)); }
	void test_case_2() { string Arg0 = "WLWRW"; string Arg1 = "RED"; verify_case(2, Arg1, finalPosition(Arg0)); }
	void test_case_3() { string Arg0 = "WWLLWRWLWLLRWW"; string Arg1 = "BLUE"; verify_case(3, Arg1, finalPosition(Arg0)); }

// END CUT HERE

//-
};

//+
int main() {
    CubeWalking ___test;
    ___test.run_test(-1);
    getchar();
}
//-
