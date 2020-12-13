/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "HamiltonPath.cpp"
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

int MOD = 1000000007;

int N;
vector<int> adj[55];
int vis[55];
bool cycle;

void dfs(int u, int p) {
    vis[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        if (!vis[v]) dfs(v, u);
        else cycle = 1;
    }
}

class HamiltonPath {
public:
   int countPaths( vector <string> roads ) {
    N = roads.size();
    for (int i = 0; i < N; i++) adj[i].clear(), vis[i] = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        if (roads[i][j]=='Y') adj[i].push_back(j);
    for (int i = 0; i < N; i++) if (adj[i].size() >= 3) return 0;
    cycle = 0;
    int C = 0, I = 0;
    for (int i = 0; i < N; i++) if (!vis[i]) {
        if (adj[i].size()) dfs(i,-1), C++;
        else I++;
    }
    if (cycle) return 0;
    long long ret = 1;
    for (int i = 2; i <= C+I; i++) ret = (ret*i)%MOD;
    for (int i = 0; i < C; i++) ret = (ret*2)%MOD;
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
			string roads[]            = {"NYN",
 "YNN",
 "NNN"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string roads[]            = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string roads[]            = {"NYY",
 "YNY",
 "YYN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string roads[]            = {"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"};
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
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
