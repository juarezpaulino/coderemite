/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheBasketballDivTwo.cpp"
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

int host[25];
int guest[25];

class TheBasketballDivTwo {
public:
    int find( vector <string> table ) {
        int N = table.size();
        int W[5] = {0};
        int c = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (i != j)
            if (table[i][j]=='W') W[i]++;
            else if (table[i][j]=='L') W[j]++;
            else host[c] = i, guest[c] = j, c++;

        int ret = 1<<30;
        for (int k = 0; k < 1<<c; k++) {
            int U[5];
            for (int j = 0; j < N; j++) U[j] = W[j];
            for (int j = 0; j < c; j++)
                if (k&(1<<j)) U[host[j]]++;
                else U[guest[j]]++;
            ret = min(ret, *max_element(U, U+N));
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
			string table[]            = {"X?", "?X"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheBasketballDivTwo().find(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string table[]            = {"XW", "LX"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheBasketballDivTwo().find(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string table[]            = {"XWL", "?XW", "WLX"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheBasketballDivTwo().find(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string table[]            = {"XW?", "LX?", "??X"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheBasketballDivTwo().find(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string table[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBasketballDivTwo().find(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string table[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBasketballDivTwo().find(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string table[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBasketballDivTwo().find(vector <string>(table, table + (sizeof table / sizeof table[0])));
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
