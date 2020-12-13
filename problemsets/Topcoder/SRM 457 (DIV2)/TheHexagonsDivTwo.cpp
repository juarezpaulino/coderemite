/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheHexagonsDivTwo.cpp"
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

long long ret;
int N, K;
int center;
int V[10];

long long countMod(int m, int n, int k) {
    long long ret = n/k;
    if (m > 0 && m <= n%k) ret++;
    return ret;
}

void go(int p) {
    if (p == 6) {
        long long v = countMod(center,N,K);
        for (int i = 0; i < 6; i++) {
            long long x = countMod(V[i],N,K);
            for (int j = 0; j < i; j++) if (V[i]==V[j]) x--;
            v *= max(0LL,x);
        }
        ret += v;
        return;
    }
    for (int v = 0; v < min(N+1,K); v++) {
        if (v == center) continue;
        if (p > 0 && V[p-1]==v) continue;
        if (p==5 && V[0]==v) continue;
        V[p] = v;
        go(p+1);
    }
}

class TheHexagonsDivTwo {
public:
    long long count( int n, int k ) {
        N = n; K = k;
        ret = 0;
        for (int i = 0; i < min(N+1,K); i++) {
            center = i;
            go(0);
        }
        return ret/6;
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
			int n                     = 7;
			int k                     = 3;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = TheHexagonsDivTwo().count(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 8;
			int k                     = 3;
			long long expected__      = 24;

			clock_t start__           = clock();
			long long received__      = TheHexagonsDivTwo().count(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 8;
			int k                     = 4;
			long long expected__      = 256;

			clock_t start__           = clock();
			long long received__      = TheHexagonsDivTwo().count(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 20;
			int k                     = 5;
			long long expected__      = 4692480;

			clock_t start__           = clock();
			long long received__      = TheHexagonsDivTwo().count(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheHexagonsDivTwo().count(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheHexagonsDivTwo().count(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheHexagonsDivTwo().count(n, k);
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
