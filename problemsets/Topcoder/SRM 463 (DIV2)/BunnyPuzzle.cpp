/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "BunnyPuzzle.cpp"
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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class BunnyPuzzle {
public:
    int theCount( vector <int> B ) {
        int ret = 0;
        int N = B.size();
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (i != j) {
            bool ok = 1;
            int p = 2*B[j]-B[i];
            int A1 = min(p,B[i]), A2 = max(p,B[i]);
            for (int k = 0; k < N; k++) if (k!=i && k!=j && A1 <= B[k] && B[k] <= A2) ok = 0;
            if (ok) ret++;
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
			int bunnies[]             = {5, 8};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BunnyPuzzle().theCount(vector <int>(bunnies, bunnies + (sizeof bunnies / sizeof bunnies[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int bunnies[]             = {-1, 0, 1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BunnyPuzzle().theCount(vector <int>(bunnies, bunnies + (sizeof bunnies / sizeof bunnies[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int bunnies[]             = {0, 1, 3};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BunnyPuzzle().theCount(vector <int>(bunnies, bunnies + (sizeof bunnies / sizeof bunnies[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int bunnies[]             = {-677, -45, -2, 3, 8, 29, 384, 867};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = BunnyPuzzle().theCount(vector <int>(bunnies, bunnies + (sizeof bunnies / sizeof bunnies[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int bunnies[]             = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BunnyPuzzle().theCount(vector <int>(bunnies, bunnies + (sizeof bunnies / sizeof bunnies[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int bunnies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BunnyPuzzle().theCount(vector <int>(bunnies, bunnies + (sizeof bunnies / sizeof bunnies[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int bunnies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BunnyPuzzle().theCount(vector <int>(bunnies, bunnies + (sizeof bunnies / sizeof bunnies[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int bunnies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BunnyPuzzle().theCount(vector <int>(bunnies, bunnies + (sizeof bunnies / sizeof bunnies[0])));
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
