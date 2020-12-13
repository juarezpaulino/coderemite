/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "NumbersAndMatches.cpp"
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int V[20];
int M;

/////////////////////////
// Seven segment Digits.
//  _
// |_|
// |_|
//
char code[10][7] = {    {1,1,0,1,1,1,1},        // 0
                        {0,0,0,1,0,1,1},        // 1
                        {1,0,1,1,1,1,0},        // 2
                        {1,0,1,1,0,1,1},        // 3
                        {0,1,1,1,0,0,1},        // 4
                        {1,1,1,0,0,1,1},        // 5
                        {1,1,1,0,1,1,1},        // 6
                        {1,0,0,1,0,0,1},        // 7
                        {1,1,1,1,1,1,1},        // 8
                        {1,1,1,1,0,1,1} };      // 9

long long DP[20][150][300];

long long go(int m, int k, int x) {
    if (k < 0) return 0;
    long long &ret = DP[m][k][x+150];
    if (ret != -1) return ret;
    ret = 0;
    if (m == M) {
        if (x==0) return ret = 1;
        return ret = 0;
    }
    int v = 0; for (int i = 0; i < 7; i++) v += code[V[m]][i];
    for (int l = 0; l < 10; l++) {
        int u = 0; for (int i = 0; i < 7; i++) u += code[l][i];
        int b = 0; for (int i = 0; i < 7; i++) if (code[V[m]][i]&&code[l][i]) b++;
        int r = v-u;
        int a = min(u-b, v-b);
        if (x*r > 0) a += fabs(r);
        if ((x+r) * x <= 0) a += fabs(x+r);
        ret += go(m+1, k-a, x+r);
    }
    return ret;
}

class NumbersAndMatches {
public:
    long long differentNumbers( long long N, int K ) {
        M = 0;
        while (N) { V[M++] = N%10; N/=10; }
        memset(DP,-1,sizeof(DP));
        return go(0,K,0);
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			long long N               = 10;
			int K                     = 1;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = NumbersAndMatches().differentNumbers(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long N               = 23;
			int K                     = 1;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = NumbersAndMatches().differentNumbers(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long N               = 66;
			int K                     = 2;
			long long expected__      = 15;

			clock_t start__           = clock();
			long long received__      = NumbersAndMatches().differentNumbers(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long N               = 888888888;
			int K                     = 100;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = NumbersAndMatches().differentNumbers(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			long long N               = 444444444444444444LL;
			int K                     = 2;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = NumbersAndMatches().differentNumbers(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long N               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = NumbersAndMatches().differentNumbers(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long N               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = NumbersAndMatches().differentNumbers(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long N               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = NumbersAndMatches().differentNumbers(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
