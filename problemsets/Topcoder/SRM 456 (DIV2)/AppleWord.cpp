/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "AppleWord.cpp"
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

class AppleWord {
public:
    int minRep( string W ) {
        if (W.size() < 5) return -1;
        int N = W.size();
        int ret = 0;
        if (tolower(W[0]) != 'a') ret++;
        if (tolower(W[N-1]) != 'e') ret++;
        if (tolower(W[N-2]) != 'l') ret++;
        for (int i = 1; i < N-2; i++) if (tolower(W[i]) != 'p') ret++;
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
			string word               = "Apple";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AppleWord().minRep(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string word               = "apPpPPlE";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AppleWord().minRep(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string word               = "APLE";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = AppleWord().minRep(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string word               = "TopCoder";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = AppleWord().minRep(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AppleWord().minRep(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AppleWord().minRep(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AppleWord().minRep(word);
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
