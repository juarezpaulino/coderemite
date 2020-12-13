/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "CutSticks.cpp"
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
#include <functional>

using namespace std;

const double EPS = 1E-10;
inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vector<int> S;
long long K, C;

bool check(double m) {
    long long u = 0, v = 0;
    for (int i = 0; i < S.size(); i++) {
        if (cmp(S[i],m)>=0) u++;
        v += (long long)(S[i]/m+EPS);
    }
    if (v >= K && u+C >= K) return true;
    return false;
}


class CutSticks {
public:
    double maxKth( vector <int> sticks, int _C, int _K ) {
        S = sticks; K = _K; C = _C;
        double lo = 0., hi = 1E9+10;
        for (int it = 0; it < 1000; it++) {
            if (cmp(hi,lo)==0) break;
            double m = (hi+lo)/2.;
            if (check(m)) lo = m; else hi = m;
        }
        return (hi+lo)/2.;
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

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int sticks[]              = {5, 8};
			int C                     = 1;
			int K                     = 1;
			double expected__         = 8.0;

			clock_t start__           = clock();
			double received__         = CutSticks().maxKth(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])), C, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int sticks[]              = {5, 8};
			int C                     = 1;
			int K                     = 2;
			double expected__         = 5.0;

			clock_t start__           = clock();
			double received__         = CutSticks().maxKth(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])), C, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int sticks[]              = {5, 8};
			int C                     = 1;
			int K                     = 3;
			double expected__         = 4.0;

			clock_t start__           = clock();
			double received__         = CutSticks().maxKth(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])), C, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int sticks[]              = {1000000000, 1000000000, 1};
			int C                     = 2;
			int K                     = 5;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = CutSticks().maxKth(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])), C, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int sticks[]              = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
			int C                     = 789;
			int K                     = 456;
			double expected__         = 34.92;

			clock_t start__           = clock();
			double received__         = CutSticks().maxKth(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])), C, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sticks[]              = ;
			int C                     = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CutSticks().maxKth(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])), C, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sticks[]              = ;
			int C                     = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CutSticks().maxKth(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])), C, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sticks[]              = ;
			int C                     = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CutSticks().maxKth(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])), C, K);
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
