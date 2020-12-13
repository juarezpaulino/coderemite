/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "NameInput.cpp"
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

int M, N;
int DP[3000][3000];
string P, U;
int adj[2][3000][256];

int go(int k, int p) {
    int &ret = DP[k][p];
    if (ret != -1) return ret;
    if (k == N) return 0;
    ret = 1<<30;
    for (int i = 0; i < 2; i++) {
        int np = adj[i][p][U[k]];
        if (np == -1) continue;
        int m = min((p+M-np)%M, (np+M-p)%M);
        ret = min(ret, m+go(k+1,np));
    }
    return ret;
}

class NameInput {
public:
    int countUpDownKeyPresses( vector <string> predictionSequence, vector <string> name ) {
        P = "";
        for (int i = 0; i < predictionSequence.size(); i++) P += predictionSequence[i];
        M = P.size();
        U = "";
        for (int i = 0; i < name.size(); i++) U += name[i];
        N = U.size();
        memset(DP,-1,sizeof(DP));
        memset(adj,-1,sizeof(adj));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j <= M/2; j++) {
                if (adj[0][i][P[(i+M+j)%M]]==-1) adj[0][i][P[(i+M+j)%M]] = (i+M+j)%M;
                if (adj[1][i][P[(i+M-j)%M]]==-1) adj[1][i][P[(i+M-j)%M]] = (i+M-j)%M;
            }
        }
        int ret = go(0,0);
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
			string predictionSequence[] = {"Jjhon"};
			string name[]             = {"John"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string predictionSequence[] = {"abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ","0123456789"};
			string name[]             = {"Joh","nAndFr","iends"};
			int expected__            = 186;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string predictionSequence[] = {"aaaabbbab","baabbabaabba"};
			string name[]             = {"bbaaababba","baababababbb"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string predictionSequence[] = {"john"};
			string name[]             = {"John"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string predictionSequence[] = {"4"};
			string name[]             = {"4444444444444"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string predictionSequence[] = {"abcABC123","cbaCBA321"};
			string name[]             = {"aB32C2AaB3c","c32bA"};
			int expected__            = 38;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string predictionSequence[] = ;
			string name[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string predictionSequence[] = ;
			string name[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string predictionSequence[] = ;
			string name[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NameInput().countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence + (sizeof predictionSequence / sizeof predictionSequence[0])), vector <string>(name, name + (sizeof name / sizeof name[0])));
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
