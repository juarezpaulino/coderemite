/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
//+

//-
#line 5 "KnightsTour.cpp"

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


////////////////////////////////////////////////////////////////////////////////

vector<string> B;

int dy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int ACN(int y, int x) {
    int v = 0;
    for (int i = 0; i < 8; i++) {
        int ny = y+dy[i],
            nx = x+dx[i];
        if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
        if (B[ny][nx]=='.') v++;
    }
    return v;
}

class KnightsTour {
public:
int visitedPositions(vector <string> board) {
    B = board;
    int y = -1, x = -1;
    FOR(i,0,8) FOR(j,0,8) if (B[i][j]=='K') y = i, x = j;
    int ret = 0;
    while (1) {
        B[y][x] = '*';
        ret++;
        int b = -1, by, bx;
        FOR(i,0,8) {
            int ny = y+dy[i],
                nx = x+dx[i];
            if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
            if (B[ny][nx]=='.') {
                int v = ACN(ny,nx);
                if (b==-1 || v < b)
                    b = v, by = ny, bx = nx;
            }
        }
        if (b == -1) break;
        y = by, x = bx;
    }
    return ret;
}

//+

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(0, Arg1, visitedPositions(Arg0)); }
	void test_case_1() { string Arr0[] = {"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, visitedPositions(Arg0)); }
	void test_case_2() { string Arr0[] = {"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, visitedPositions(Arg0)); }
	void test_case_3() { string Arr0[] = {"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(3, Arg1, visitedPositions(Arg0)); }
	void test_case_4() { string Arr0[] = {"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(4, Arg1, visitedPositions(Arg0)); }

// END CUT HERE

//-
};

//+
int main() {
    KnightsTour ___test;
    ___test.run_test(-1);
    getchar();
}
//-
