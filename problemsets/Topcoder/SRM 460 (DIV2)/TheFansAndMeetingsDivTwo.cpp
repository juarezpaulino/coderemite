/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheFansAndMeetingsDivTwo.cpp"
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

class TheFansAndMeetingsDivTwo {
public:
    double find( vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB ) {
        double ret = 0;
        int N = minJ.size();
        for (int i = 0; i <= 50; i++) {
            double p1 = 0., p2 = 0.;
            for (int j = 0; j < N; j++) {
                if (minJ[j] <= i && i <= maxJ[j]) p1 += 1. / N / (maxJ[j]-minJ[j]+1);
                if (minB[j] <= i && i <= maxB[j]) p2 += 1. / N / (maxB[j]-minB[j]+1);
            }
            ret += p1*p2;
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
			int minJ[]                = {1};
			int maxJ[]                = {3};
			int minB[]                = {1};
			int maxB[]                = {1};
			double expected__         = 0.3333333333333333;

			clock_t start__           = clock();
			double received__         = TheFansAndMeetingsDivTwo().find(vector <int>(minJ, minJ + (sizeof minJ / sizeof minJ[0])), vector <int>(maxJ, maxJ + (sizeof maxJ / sizeof maxJ[0])), vector <int>(minB, minB + (sizeof minB / sizeof minB[0])), vector <int>(maxB, maxB + (sizeof maxB / sizeof maxB[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int minJ[]                = {5, 7, 7, 1, 6, 1, 1};
			int maxJ[]                = {8, 9, 7, 3, 9, 5, 3};
			int minB[]                = {9, 12, 10, 14, 50, 9, 10};
			int maxB[]                = {9, 13, 50, 15, 50, 12, 11};
			double expected__         = 0.014880952380952378;

			clock_t start__           = clock();
			double received__         = TheFansAndMeetingsDivTwo().find(vector <int>(minJ, minJ + (sizeof minJ / sizeof minJ[0])), vector <int>(maxJ, maxJ + (sizeof maxJ / sizeof maxJ[0])), vector <int>(minB, minB + (sizeof minB / sizeof minB[0])), vector <int>(maxB, maxB + (sizeof maxB / sizeof maxB[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int minJ[]                = {44};
			int maxJ[]                = {47};
			int minB[]                = {4};
			int maxB[]                = {7};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = TheFansAndMeetingsDivTwo().find(vector <int>(minJ, minJ + (sizeof minJ / sizeof minJ[0])), vector <int>(maxJ, maxJ + (sizeof maxJ / sizeof maxJ[0])), vector <int>(minB, minB + (sizeof minB / sizeof minB[0])), vector <int>(maxB, maxB + (sizeof maxB / sizeof maxB[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int minJ[]                = {1, 6, 3, 1, 4, 3, 5, 1};
			int maxJ[]                = {7, 8, 5, 7, 9, 7, 9, 3};
			int minB[]                = {5, 1, 5, 3, 1, 2, 4, 1};
			int maxB[]                = {9, 2, 7, 9, 4, 5, 4, 9};
			double expected__         = 0.11562305130385474;

			clock_t start__           = clock();
			double received__         = TheFansAndMeetingsDivTwo().find(vector <int>(minJ, minJ + (sizeof minJ / sizeof minJ[0])), vector <int>(maxJ, maxJ + (sizeof maxJ / sizeof maxJ[0])), vector <int>(minB, minB + (sizeof minB / sizeof minB[0])), vector <int>(maxB, maxB + (sizeof maxB / sizeof maxB[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int minJ[]                = ;
			int maxJ[]                = ;
			int minB[]                = ;
			int maxB[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFansAndMeetingsDivTwo().find(vector <int>(minJ, minJ + (sizeof minJ / sizeof minJ[0])), vector <int>(maxJ, maxJ + (sizeof maxJ / sizeof maxJ[0])), vector <int>(minB, minB + (sizeof minB / sizeof minB[0])), vector <int>(maxB, maxB + (sizeof maxB / sizeof maxB[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int minJ[]                = ;
			int maxJ[]                = ;
			int minB[]                = ;
			int maxB[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFansAndMeetingsDivTwo().find(vector <int>(minJ, minJ + (sizeof minJ / sizeof minJ[0])), vector <int>(maxJ, maxJ + (sizeof maxJ / sizeof maxJ[0])), vector <int>(minB, minB + (sizeof minB / sizeof minB[0])), vector <int>(maxB, maxB + (sizeof maxB / sizeof maxB[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int minJ[]                = ;
			int maxJ[]                = ;
			int minB[]                = ;
			int maxB[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFansAndMeetingsDivTwo().find(vector <int>(minJ, minJ + (sizeof minJ / sizeof minJ[0])), vector <int>(maxJ, maxJ + (sizeof maxJ / sizeof maxJ[0])), vector <int>(minB, minB + (sizeof minB / sizeof minB[0])), vector <int>(maxB, maxB + (sizeof maxB / sizeof maxB[0])));
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
