/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "EasySequence.cpp"
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

vector<int> V, B;

int go() {
    int N = B.size();
    for (int i = 0; i < V.size(); i++) {
        bool ok = 1;
        for (int j = 0; j < N; j++) if (V[i+j] != B[j]) ok = 0;
        if (ok) return i;
    }
    return -1;
}

class EasySequence {
public:
    int find( vector <int> A, vector <int> _B ) {
        V = A; B = _B;
        int sum = 0;
        for (int i = 0; i < A.size(); i++) sum += A[i];
        int l = 0;
        for (int i = 0; i < 100000; i++) {
            int v = sum%10;
            V.push_back(v);
            sum += (v-V[l++]);
        }
        return go();
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
			int A[]                   = {1,2,3};
			int B[]                   = {0,7,8,5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EasySequence().find(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {1,2,8};
			int B[]                   = {7,4,2,3};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = EasySequence().find(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {1,2,3,4,5};
			int B[]                   = {4,5};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EasySequence().find(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {1};
			int B[]                   = {1,1,1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EasySequence().find(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EasySequence().find(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EasySequence().find(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EasySequence().find(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
