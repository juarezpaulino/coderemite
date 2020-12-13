/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "ToolsBox.cpp"
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

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}

class ToolsBox {
public:
    int countTools( vector <string> need ) {
        set<string> S;
        for (int i = 0; i < need.size(); i++) {
            vector<string> tok = tokenize(need[i], " ");
            for (int j = 0; j < tok.size(); j++) S.insert(tok[j]);
        }
        return S.size();
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
			string need[]             = {"SAW HAMMER SCREWDRIVER","SCREWDRIVER HAMMER KNIFE"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ToolsBox().countTools(vector <string>(need, need + (sizeof need / sizeof need[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string need[]             = {"SAW"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ToolsBox().countTools(vector <string>(need, need + (sizeof need / sizeof need[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string need[]             = {"SAW","SAW"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ToolsBox().countTools(vector <string>(need, need + (sizeof need / sizeof need[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string need[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToolsBox().countTools(vector <string>(need, need + (sizeof need / sizeof need[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string need[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToolsBox().countTools(vector <string>(need, need + (sizeof need / sizeof need[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string need[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToolsBox().countTools(vector <string>(need, need + (sizeof need / sizeof need[0])));
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
