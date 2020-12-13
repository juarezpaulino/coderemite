/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheProduct.cpp"
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

const long long INF = 1LL<<61;

int K, D, N;
vector<int> V;
long long DP[2][55][55];

long long go(int u, int v, int k) {
    long long &ret = DP[u][v][k];
    if (ret != INF+1) return ret;
    if (k == K-1) return ret = V[v];
    if (u == 0) {
        ret = INF;
        if (N-v+k < K) return ret;
        for (int i = v+1; i < N && i-v <= D; i++) {
            long long a = go(0,i,k+1);
            if (a < INF) ret = min(ret, V[v]*a);
            a = go(1,i,k+1);
            if (a > -INF) ret = min(ret, V[v]*a);
        }
    }
    else {
        ret = -INF;
        if (N-v+k < K) return ret;
        for (int i = v+1; i < N && i-v <= D; i++) {
            long long a = go(0,i,k+1);
            if (a < INF) ret = max(ret, V[v]*a);
            a = go(1,i,k+1);
            if (a > -INF) ret = max(ret, V[v]*a);
        }
    }
    return ret;
}

class TheProduct {
public:
    long long maxProduct( vector <int> numbers, int k, int maxDist ) {
        V = numbers; K = k; D = maxDist;
        N = V.size();
        for (int l = 0; l < 2; l++) for (int i = 0; i <= N; i++) for (int j = 0; j <= K; j++) DP[l][i][j] = INF+1;
        long long ret = -INF;
        for (int i = 0; i < N; i++) ret = max(ret, go(1,i,0));
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

	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) {
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
			int numbers[]             = {7, 4, 7};
			int k                     = 2;
			int maxDist               = 1;
			long long expected__      = 28;

			clock_t start__           = clock();
			long long received__      = TheProduct().maxProduct(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), k, maxDist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int numbers[]             = {7, 4, 7};
			int k                     = 2;
			int maxDist               = 50;
			long long expected__      = 49;

			clock_t start__           = clock();
			long long received__      = TheProduct().maxProduct(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), k, maxDist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int numbers[]             = {-3, -5, -8, -9, -1, -2};
			int k                     = 3;
			int maxDist               = 3;
			long long expected__      = -10;

			clock_t start__           = clock();
			long long received__      = TheProduct().maxProduct(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), k, maxDist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int numbers[]             = {3, 0, -2, 10, 0, 0, 3, -8, 0, 2};
			int k                     = 2;
			int maxDist               = 2;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = TheProduct().maxProduct(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), k, maxDist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int numbers[]             = ;
			int k                     = ;
			int maxDist               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheProduct().maxProduct(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), k, maxDist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int numbers[]             = ;
			int k                     = ;
			int maxDist               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheProduct().maxProduct(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), k, maxDist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numbers[]             = ;
			int k                     = ;
			int maxDist               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheProduct().maxProduct(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), k, maxDist);
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
