/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "Desertification.cpp"
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

class Desertification {
public:
    int desertArea( vector <string> I, int T ) {
        vector<string> cur;
        int M = I.size(), N = I[0].size();
        int dy[] = {-1, 0, 1, 0};
        int dx[] = {0, 1, 0, -1};
        T = min(T,100);
        while (T--) {
            cur = I;
            for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (I[i][j]=='F') {
                bool ok = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i+dy[k], nx = j+dx[k];
                    if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
                    if (cur[ny][nx]=='D') ok = 1;
                }
                if (ok) I[i][j] = 'D';
            }
        }
        int ret = 0;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (I[i][j]=='D') ret++;
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
			string island[]           = {"FFF",
 "FDF",
 "FFF"};
			int T                     = 1;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string island[]           = {"FFF",
 "FDF",
 "FFF"};
			int T                     = 2;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string island[]           = {"FFFFF",
 "FFDFF",
 "FFFFD",
 "FFFFF",
 "FFFFF"};
			int T                     = 2;
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string island[]           = {"FFFFFF",
 "FFFFFF",
 "FFFFFF",
 "FFFFFF"};
			int T                     = 1000000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string island[]           = {"FFFFFDFFFF",
 "FDFDFFFFFF",
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "DDFFFFFFFF",
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "FFFFFFFDFF",
 "FFFFFFFDFF",
 "FFFFDDFFFF"};
			int T                     = 3;
			int expected__            = 90;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string island[]           = {"FFFFFDFFFF",
 "FDFDFFFFFF",
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "DDFFFFFFFF",
 "FFFFFFFFFD",
 "FFFFFFFFFF",
 "FFFFFFFDFF",
 "FFFFFFFDFF",
 "FFFFDDFFFF"};
			int T                     = 98765432;
			int expected__            = 100;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string island[]           = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string island[]           = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string island[]           = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Desertification().desertArea(vector <string>(island, island + (sizeof island / sizeof island[0])), T);
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
