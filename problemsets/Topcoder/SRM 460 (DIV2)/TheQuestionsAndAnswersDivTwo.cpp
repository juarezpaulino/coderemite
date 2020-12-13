/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheQuestionsAndAnswersDivTwo.cpp"
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

class TheQuestionsAndAnswersDivTwo {
public:
    int find( vector <string> Q ) {
        set<string> S;
        int c = 0;
        for (int i = 0; i < Q.size(); i++) S.insert(Q[i]);
        return 1<<S.size();
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
			string questions[]        = {"How_are_you_doing?", "How_do_you_like_our_country?", "How_are_you_doing?"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivTwo().find(vector <string>(questions, questions + (sizeof questions / sizeof questions[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string questions[]        = {"Whazzup?"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivTwo().find(vector <string>(questions, questions + (sizeof questions / sizeof questions[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string questions[]        = {"Are_you_ready?", "Are_you_ready?", "Are_you_ready?", "Are_you_ready?"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivTwo().find(vector <string>(questions, questions + (sizeof questions / sizeof questions[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string questions[]        = {"Do_you_like_my_story?", "Do_you_like_my_story", "DO_YOU_LIKE_MY_STORY?", "Do__you__like__my__story?"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivTwo().find(vector <string>(questions, questions + (sizeof questions / sizeof questions[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string questions[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivTwo().find(vector <string>(questions, questions + (sizeof questions / sizeof questions[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string questions[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivTwo().find(vector <string>(questions, questions + (sizeof questions / sizeof questions[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string questions[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivTwo().find(vector <string>(questions, questions + (sizeof questions / sizeof questions[0])));
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
