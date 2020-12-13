/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheTriangleBothDivs.cpp"
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

class TheTriangleBothDivs {
public:
    string fix( string time ) {
        string ret = "99:99";
        int m = 0;
        if (time[3]=='?') m = m*10 + 0; else m = m*10+time[3]-'0';
        if (time[4]=='?') m = m*10 + 0; else m = m*10+time[4]-'0';
        for (int h = 0; h <= 23; h++) for (int g = -9; g <= 9; g++) {
            char S[101];
            sprintf(S, "%02d:%02d GMT%c%d", h, m, (g >= 0) ? '+' : '-', abs(g));
            bool ok = 1;
            for (int i = 0; i < time.size(); i++)
                if (time[i] != S[i]) {
                    if (time[i]!='?')
                        ok = 0;
                }
            if (!ok) continue;
            int H = (h+24-g)%24;
            sprintf(S, "%02d:%02d", H, m);
            if (S < ret) ret = S;
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

	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) {
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
			cerr << "    Expected: \"" << expected << "\"" << endl;
			cerr << "    Received: \"" << received << "\"" << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string time               = "17:45 GMT-4";
			string expected__         = "21:45";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string time               = "16:?? GMT??";
			string expected__         = "00:00";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string time               = "?1:34 GMT-9";
			string expected__         = "06:34";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string time               = "??:?? GMT??";
			string expected__         = "00:00";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string time               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string time               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string time               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
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
