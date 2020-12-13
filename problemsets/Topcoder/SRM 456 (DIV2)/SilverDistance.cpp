/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "SilverDistance.cpp"
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

class SilverDistance {
public:
    int minSteps( int sx, int sy, int qx, int qy ) {
        int ret = 0;
        if ((abs(sx-qx)+abs(sy-qy))%2)
            ret++, sy++;
        ret += max(abs(sx-qx), abs(sy-qy));
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

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
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
			int sx                    = 1;
			int sy                    = 0;
			int gx                    = 1;
			int gy                    = 9;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int sx                    = 0;
			int sy                    = 0;
			int gx                    = -4;
			int gy                    = 3;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int sx                    = 0;
			int sy                    = 0;
			int gx                    = 5;
			int gy                    = 8;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int sx                    = -487617;
			int sy                    = 826524;
			int gx                    = 892309;
			int gy                    = -918045;
			int expected__            = 1744571;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int sx                    = -27857;
			int sy                    = 31475;
			int gx                    = -27857;
			int gy                    = 31475;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sx                    = ;
			int sy                    = ;
			int gx                    = ;
			int gy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sx                    = ;
			int sy                    = ;
			int gx                    = ;
			int gy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sx                    = ;
			int sy                    = ;
			int gx                    = ;
			int gy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
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
