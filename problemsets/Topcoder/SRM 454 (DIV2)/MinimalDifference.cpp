/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "MinimalDifference.cpp"
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
#include <cmath>

using namespace std;

int sum(int A) {
    int ret = 0;
    while (A) { ret += A%10; A/=10; }
    return ret;
}

class MinimalDifference {
public:
    int findNumber( int A, int B, int C ) {
        int ret = -1, x = 1<<30;
        int v = sum(C);
        for (int i = A; i <= B; i++) {
            int u = sum(i);
            if (fabs(u-v) < x) x = fabs(u-v), ret = i;
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
			int A                     = 1;
			int B                     = 9;
			int C                     = 10;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MinimalDifference().findNumber(A, B, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 11;
			int B                     = 20;
			int C                     = 20;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = MinimalDifference().findNumber(A, B, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 1;
			int B                     = 1;
			int C                     = 999;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MinimalDifference().findNumber(A, B, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 100;
			int B                     = 1000;
			int C                     = 99;
			int expected__            = 189;

			clock_t start__           = clock();
			int received__            = MinimalDifference().findNumber(A, B, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 1987;
			int B                     = 9123;
			int C                     = 1;
			int expected__            = 2000;

			clock_t start__           = clock();
			int received__            = MinimalDifference().findNumber(A, B, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinimalDifference().findNumber(A, B, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinimalDifference().findNumber(A, B, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinimalDifference().findNumber(A, B, C);
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
