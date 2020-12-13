/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheCitiesAndRoadsDivTwo.cpp"
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

int N;
vector<string> M;
map<vector<int>, int> DP;

int go(vector<int> C) {
    if (DP.count(C)) return DP[C];
    int &ret = DP[C];
    ret = 0;
    int n = C.size();
    if (n == 1) return ret = 1;
    vector<int> A, B;
    for (int k = 0; k < 1<<(n-2); k++) {
        int bc = __builtin_popcount(k) + 1;
        int tn = bc;
        int sumA = C[n-2];
        A.resize(tn);
        A[--tn] = C[n-2];
        for (int j = n-3; j >= 0; j--) {
            if (k&(1<<j)) {
                A[--tn] = C[j];
                sumA += C[j];
            }
        }
        int sumB = C[n-1];
        tn = n - bc;
        B.resize(tn);
        B[--tn] = C[n-1];
        for (int j = n-3; j >= 0; j--) {
            if ( !(k&(1<<j)) ) {
                B[--tn] = C[j];
            }
        }
        int cAB = sumA * sumB;
        int wA  = go(A);
        int wB  = go(B);

        ret += wA*wB*cAB;
    }
    return ret;
}

class TheCitiesAndRoadsDivTwo {
public:
    int find( vector <string> map ) {
        M = map;
        N = M.size();
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            if (M[i][k]=='Y'&&M[k][j]=='Y') M[i][j] = 'Y';
        vector<int> C;
        vector<bool> marc(N,0);
        for (int i = 0; i < N; i++) {
            if (!marc[i]) {
                marc[i] = 1;
                int c = 1;
                for (int j = 0; j < N; j++) if (!marc[j] && M[i][j]=='Y') marc[j] = 1, c++;
                C.push_back(c);
            }
        }
        sort(C.begin(), C.end());
        return go(C);
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
			string map[]              = {"NN",
 "NN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheCitiesAndRoadsDivTwo().find(vector <string>(map, map + (sizeof map / sizeof map[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string map[]              = {"NY",
 "YN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheCitiesAndRoadsDivTwo().find(vector <string>(map, map + (sizeof map / sizeof map[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string map[]              = {"NNY",
 "NNN",
 "YNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheCitiesAndRoadsDivTwo().find(vector <string>(map, map + (sizeof map / sizeof map[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string map[]              = {"NYNN",
 "YNNN",
 "NNNY",
 "NNYN"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheCitiesAndRoadsDivTwo().find(vector <string>(map, map + (sizeof map / sizeof map[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string map[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheCitiesAndRoadsDivTwo().find(vector <string>(map, map + (sizeof map / sizeof map[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string map[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheCitiesAndRoadsDivTwo().find(vector <string>(map, map + (sizeof map / sizeof map[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string map[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheCitiesAndRoadsDivTwo().find(vector <string>(map, map + (sizeof map / sizeof map[0])));
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
