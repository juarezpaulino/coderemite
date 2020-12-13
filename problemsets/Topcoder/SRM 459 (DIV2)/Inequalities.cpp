/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "Inequalities.cpp"
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

class Inequalities {
public:
    int maximumSubset( vector <string> I ) {
        int ret = 0;
        for (double v = -.5; v <= 1000.5; v+=.5) {
            int k = 0;
            for (int i = 0; i < I.size(); i++) {
                string a, b;
                int u;
                istringstream is(I[i]);
                is >> a >> b >> u;
                bool ok = 0;
                if (b == ">" && cmp(v,u)>0) ok = 1;
                if (b == ">=" && cmp(v,u)>=0) ok = 1;
                if (b == "=" && cmp(v,u)==0) ok = 1;
                if (b == "<" && cmp(v,u)<0) ok = 1;
                if (b == "<=" && cmp(v,u)<=0) ok = 1;
                if (ok) k++;
            }
            ret = max(ret, k);
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
			string inequalities[]     = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string inequalities[]     = {"X < 0","X <= 0"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string inequalities[]     = {"X = 1","X = 2","X = 3","X > 0"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string inequalities[]     = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string inequalities[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string inequalities[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string inequalities[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
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
