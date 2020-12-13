/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "WordsGame.cpp"
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class WordsGame {
public:
    int minimumSwaps( vector <string> G, string W ) {
        map<char,int> M;
        for (int i = 0; i < W.size(); i++) M[W[i]] = i;
        int N = G.size();
        string w = W;
        sort(w.begin(), w.end());
        int ret = 1<<30;
        for (int i = 0; i < N; i++) {
            string a = "";
            for (int j = 0; j < N; j++) a += G[i][j];
            string b = a;
            sort(b.begin(), b.end());
            if (b != w) continue;
            int c = 0;
            int U[55] = {0};
            for (int i = 0; i < N; i++) if (!U[i]) {
                int x = i;
                do {
                    U[x] = 1;
                    x = M[a[x]];
                } while (!U[x]);
                c++;
            }
            if (N-c < ret) ret = N-c;
        }
        for (int j = 0; j < N; j++) {
            string a = "";
            for (int i = 0; i < N; i++) a += G[i][j];
            string b = a;
            sort(b.begin(), b.end());
            if (b != w) continue;
            int c = 0;
            int U[55] = {0};
            for (int i = 0; i < N; i++) if (!U[i]) {
                int x = i;
                do {
                    U[x] = 1;
                    x = M[a[x]];
                } while (!U[x]);
                c++;
            }
            if (N-c < ret) ret = N-c;
        }
        if (ret == 1<<30) return -1;
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
			string grid[]             = {"Mu",
 "uM"};
			string word               = "Mu";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"sdf",
 "bca",
 "hgf"};
			string word               = "abc";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"cdf",
 "bca",
 "agf"};
			string word               = "abc";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"xSZB",
 "gbHk",
 "kbgH",
 "WFSg"};
			string word               = "bkHg";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string grid[]             = {"eKUNGHktLB",
 "EtBFDndTlG",
 "RRFHmjwrDs",
 "eKYsHlYhlu",
 "ljxyJSwTds",
 "dUQToyWHvl",
 "azDPWRwioE",
 "EARdktoDBh",
 "dmIqcGSvCE",
 "wXypNQEMxz"};
			string word               = "oDmWcJHGNk";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string grid[]             = {"ab",
 "bA"};
			string word               = "aB";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string grid[]             = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string grid[]             = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string grid[]             = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WordsGame().minimumSwaps(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), word);
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
