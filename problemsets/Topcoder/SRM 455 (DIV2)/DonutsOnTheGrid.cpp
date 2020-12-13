/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "DonutsOnTheGrid.cpp"
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

class DonutsOnTheGrid {
public:
    long long calc( int H, int W, int seed, int threshold ) {
        vector<string> A(H, string(W,'.'));
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
            seed = (seed * 25173 + 13849)%65536;
            if (seed < threshold) A[i][j] = '0';
        }
        int Y[400][400] = {0};
        for (int i = H-1; i >= 0; i--) for (int j = 0; j < W; j++)
            Y[i][j] = Y[i+1][j] + ((A[i][j]=='0') ? 1 : 0);
        long long ret = 0;
        for (int u = 0; u < H; u++) for (int v = u+2; v < H; v++) {
            int last = -2, sum = 0;
            for (int k = 0; k < W; k++) {
                if (A[u][k]=='.' || A[v][k]=='.')
                    sum = 0;
                else if (Y[u][k]-Y[v+1][k]==v-u+1) {
                    if (last+1 == k) ret += sum-1;
                    else ret += sum;
                    sum++;
                    last = k;
                }
            }
        }
        return ret;
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
			int H                     = 5;
			int W                     = 5;
			int seed                  = 222;
			int threshold             = 55555;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = DonutsOnTheGrid().calc(H, W, seed, threshold);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int H                     = 5;
			int W                     = 6;
			int seed                  = 121;
			int threshold             = 58000;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = DonutsOnTheGrid().calc(H, W, seed, threshold);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int H                     = 4;
			int W                     = 5;
			int seed                  = 6;
			int threshold             = 50000;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = DonutsOnTheGrid().calc(H, W, seed, threshold);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int H                     = 4;
			int W                     = 4;
			int seed                  = 1;
			int threshold             = 65536;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = DonutsOnTheGrid().calc(H, W, seed, threshold);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int H                     = ;
			int W                     = ;
			int seed                  = ;
			int threshold             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = DonutsOnTheGrid().calc(H, W, seed, threshold);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int H                     = ;
			int W                     = ;
			int seed                  = ;
			int threshold             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = DonutsOnTheGrid().calc(H, W, seed, threshold);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int H                     = ;
			int W                     = ;
			int seed                  = ;
			int threshold             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = DonutsOnTheGrid().calc(H, W, seed, threshold);
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
