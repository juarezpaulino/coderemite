/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheSquareDivTwo.cpp"
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

class TheSquareDivTwo {
public:
    vector <string> solve( vector <string> board ) {
        int M = board.size();
        vector<string> B(M, string(M,'.'));
        for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) B[j][i] = board[i][j];
        for (int j = 0; j < M; j++) {
            int k = 0;
            for (int i = 0; i < M; i++) if (B[i][j]=='C') k++;
            for (int i = 0; i < M-k; i++) B[i][j] = '.';
            for (int i = M-k; i < M; i++) B[i][j] = 'C';
        }
        return B;
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

	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) {
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
			string board[]            = {"..",
 "C."};
			string expected__[]       = {"..", ".C" };

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"CC",
 ".C"};
			string expected__[]       = {"C.", "CC" };

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string board[]            = {".C..",
 "CC.C",
 "..C.",
 "CCCC"};
			string expected__[]       = {"...C", ".C.C", ".C.C", "CCCC" };

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"...CCC",
 "...CCC",
 "...CCC",
 "CCC...",
 "CCC...",
 "CCC..."};
			string expected__[]       = {"......", "......", "......", "CCCCCC", "CCCCCC", "CCCCCC" };

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string board[]            = {".....C",
 "....CC",
 "...CCC",
 "..CCCC",
 ".CCCCC",
 "CCCCCC"};
			string expected__[]       = {".....C", "....CC", "...CCC", "..CCCC", ".CCCCC", "CCCCCC" };

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"C.C..C.C..C..C.",
 "CCC...C..CCC.C.",
 "......CC...CCCC",
 ".C..CC.C.C.C.C.",
 "C....C.C......C",
 ".....C..CCCCC.C",
 "CCC.......CCCCC",
 "..C.C..C.C...C.",
 "CCC....CCC.CC..",
 "CC.CCCC.CCCC...",
 ".C..C.CC.C.CC.C",
 "C.CCCC..CC..C.C",
 ".CCCC.CCCCCC...",
 "..C...C.CCC.CC.",
 "CCCC..CCC.C...."};
			string expected__[]       = {"...............", "...............", "...............", "...............", "...............", ".........C..C..", ".........C.CC..", ".C....C.CCCCC.C", ".C.C.CC.CCCCCCC", "CCCC.CC.CCCCCCC", "CCCC.CCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC" };

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = TheSquareDivTwo().solve(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
