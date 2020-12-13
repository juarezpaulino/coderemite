/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "SteeplechaseTrack.cpp"
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

class SteeplechaseTrack {
public:
    int maxComplexity( vector <string> fences, vector <string> tracks, int N ) {
        int M = tracks.size() + 2;
        vector<int> W(M, 0), C(M,0);
        vector<vector<int> > G(M, vector<int>(M, 0));
        for (int i = 0; i < fences.size(); i++) {
            W[i] = fences[i][0]-'0';
            C[i] = G[M-2][i] = fences[i][1]-'0';
            G[i][M-1] = fences[i][2]-'0';
        }
        for (int i = 0; i < M-2; i++) for (int j = 0; j < M-2; j++) G[i][j] = tracks[i][j]-'0';
        for (int i = 0; i < N; i++) {
            vector<int> D = C;
            for (int i = 0; i < M; i++) if (C[i] > 0)
                for (int j = 0; j < M; j++) if (G[i][j] > 0)
                    D[j] = max(D[j],C[i]+W[i]+G[i][j]);
            C = D;
        }
        if (C[M-1]==0) return -1;
        return C[M-1];
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
			string fences[]           = {"310",
 "300",
 "301"};
			string tracks[]           = {"010",
 "001",
 "000"};
			int N                     = 4;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = SteeplechaseTrack().maxComplexity(vector <string>(fences, fences + (sizeof fences / sizeof fences[0])), vector <string>(tracks, tracks + (sizeof tracks / sizeof tracks[0])), N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string fences[]           = {"923"};
			string tracks[]           = {"1"};
			int N                     = 100;
			int expected__            = 1004;

			clock_t start__           = clock();
			int received__            = SteeplechaseTrack().maxComplexity(vector <string>(fences, fences + (sizeof fences / sizeof fences[0])), vector <string>(tracks, tracks + (sizeof tracks / sizeof tracks[0])), N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string fences[]           = {"111",
 "222",
 "333"};
			string tracks[]           = {"743",
 "985",
 "380"};
			int N                     = 1;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = SteeplechaseTrack().maxComplexity(vector <string>(fences, fences + (sizeof fences / sizeof fences[0])), vector <string>(tracks, tracks + (sizeof tracks / sizeof tracks[0])), N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string fences[]           = {"101",
 "202",
 "303"};
			string tracks[]           = {"659",
 "431",
 "770"};
			int N                     = 5;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SteeplechaseTrack().maxComplexity(vector <string>(fences, fences + (sizeof fences / sizeof fences[0])), vector <string>(tracks, tracks + (sizeof tracks / sizeof tracks[0])), N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string fences[]           = {"693",
 "982",
 "236"};
			string tracks[]           = {"603",
 "986",
 "780"};
			int N                     = 10;
			int expected__            = 172;

			clock_t start__           = clock();
			int received__            = SteeplechaseTrack().maxComplexity(vector <string>(fences, fences + (sizeof fences / sizeof fences[0])), vector <string>(tracks, tracks + (sizeof tracks / sizeof tracks[0])), N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string fences[]           = ;
			string tracks[]           = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SteeplechaseTrack().maxComplexity(vector <string>(fences, fences + (sizeof fences / sizeof fences[0])), vector <string>(tracks, tracks + (sizeof tracks / sizeof tracks[0])), N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string fences[]           = ;
			string tracks[]           = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SteeplechaseTrack().maxComplexity(vector <string>(fences, fences + (sizeof fences / sizeof fences[0])), vector <string>(tracks, tracks + (sizeof tracks / sizeof tracks[0])), N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string fences[]           = ;
			string tracks[]           = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SteeplechaseTrack().maxComplexity(vector <string>(fences, fences + (sizeof fences / sizeof fences[0])), vector <string>(tracks, tracks + (sizeof tracks / sizeof tracks[0])), N);
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
