/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "NotTwo.cpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <functional>
#include <queue>
#include <algorithm>

using namespace std;

class NotTwo {
public:
    int maxStones( int width, int height ) {
        char M[1010][1010] = {0};
        int ret = 0;
        for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) {
            bool ok = 1;
            if (i > 1) ok &= !(M[i-2][j]);
            if (j > 1) ok &= !(M[i][j-2]);
            if (ok) ret++, M[i][j] = 1;
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
			int width                 = 3;
			int height                = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int width                 = 3;
			int height                = 3;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int width                 = 8;
			int height                = 5;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int width                 = ;
			int height                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int width                 = ;
			int height                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int width                 = ;
			int height                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
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
