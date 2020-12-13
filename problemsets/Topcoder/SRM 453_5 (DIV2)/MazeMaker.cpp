/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "MazeMaker.cpp"
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

int M, N, K;
int D[55][55];

class MazeMaker {
public:
    int longestPath( vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol ) {
        M = maze.size(); N = maze[0].size(); K = moveRow.size();
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) D[i][j] = 1<<30;
        queue<pair<int,int> > q;
        q.push(make_pair(startRow, startCol));
        D[startRow][startCol] = 0;
        while (!q.empty()) {
            int y = q.front().first, x = q.front().second;
            q.pop();
            for (int k = 0; k < K; k++) {
                int ny = y+moveRow[k], nx = x+moveCol[k];
                if (ny < 0 || nx < 0 || ny >= M || nx >= N || maze[ny][nx]!='.' || D[ny][nx]!=1<<30) continue;
                D[ny][nx] = D[y][x]+1;
                q.push(make_pair(ny,nx));
            }
        }
        int ret = 0;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (maze[i][j]=='.') ret = max(ret, D[i][j]);
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
			string maze[]             = {"...",
 "...",
 "..."};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1,0,-1,0};
			int moveCol[]             = {0,1,0,-1};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string maze[]             = {"...",
 "...",
 "..."};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1, 0, -1, 0, 1, 1, -1, -1};
			int moveCol[]             = {0, 1, 0, -1, 1, -1, 1, -1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string maze[]             = {"X.X",
 "...",
 "XXX",
 "X.X"};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1, 0, -1, 0};
			int moveCol[]             = {0, 1, 0, -1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string maze[]             = {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."};
			int startRow              = 5;
			int startCol              = 0;
			int moveRow[]             = {1, 0, -1, 0,-2, 1};
			int moveCol[]             = {0, -1, 0, 1, 3, 0};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string maze[]             = {"......."};
			int startRow              = 0;
			int startCol              = 0;
			int moveRow[]             = {1, 0, 1, 0, 1, 0};
			int moveCol[]             = {0, 1, 0, 1, 0, 1};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string maze[]             = {"..X.X.X.X.X.X."};
			int startRow              = 0;
			int startCol              = 0;
			int moveRow[]             = {2,0,-2,0};
			int moveCol[]             = {0,2,0,-2};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
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
