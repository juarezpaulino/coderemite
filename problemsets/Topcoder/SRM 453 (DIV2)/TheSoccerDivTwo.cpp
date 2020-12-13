/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheSoccerDivTwo.cpp"
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

int N;
vector<int> P;
int DP[55][110];

int go(int k, int w) {
    int &ret = DP[k][w+50];
    if (ret != -1) return ret;
    if (k == N) {
        if (w == 0) return ret = 0;
        return ret = 1<<30;
    }
    ret = 1<<30;
    ret = min(ret, ((P[k] > P[0]) ? 1 : 0) + go(k+1, w-1));
    ret = min(ret, ((P[k]+3 > P[0]) ? 1 : 0) + go(k+1, w+1));
    ret = min(ret, ((P[k]+1 > P[0]) ? 1 : 0) + go(k+1, w));
    return ret;
}

class TheSoccerDivTwo {
public:
    int find( vector <int> points ) {
        P = points;
        N = P.size();
        P[0] += 3;
        for (int i = 0; i <= N; i++) for (int j = 0; j < 110; j++) DP[i][j] = -1;
        int ret = go(1,1)+1;
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
			int points[]              = {4, 7};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheSoccerDivTwo().find(vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int points[]              = {4, 7, 7, 7};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheSoccerDivTwo().find(vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int points[]              = {5, 9, 11, 9, 10, 9};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheSoccerDivTwo().find(vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int points[]              = {2, 1, 3, 7, 6, 5, 3, 4, 2, 6, 5, 1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheSoccerDivTwo().find(vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int points[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSoccerDivTwo().find(vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int points[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSoccerDivTwo().find(vector <int>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int points[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSoccerDivTwo().find(vector <int>(points, points + (sizeof points / sizeof points[0])));
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
