/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "ColoringRectangle.cpp"
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

double compute(double d, double y) {
    return sqrt(d*d-y*y) / 2.;
}

class ColoringRectangle {
public:
    int chooseDisks( int width, int height, vector <int> red, vector <int> blue ) {
        sort(red.begin(), red.end(), greater<int>());
        sort(blue.begin(), blue.end(), greater<int>());
        int ret = 1<<30;
        for (int k = 0; k < 2; k++) {
            double x = 0;
            int v = 0;
            for (int i = 0; ; i++) {
                int j = i/2;
                if (i%2==0) {
                    if (j >= red.size()) break;
                    if (red[j] < height) break;
                    x += 2*compute(red[j], height);
                    v++;
                }
                else {
                    if (j >= blue.size()) break;
                    if (blue[j] < height) break;
                    x += 2*compute(blue[j], height);
                    v++;
                }
                if (cmp(x,width)>=0) { ret = min(ret, v); break; }
            }
            swap(blue,red);
        }
        return ret==1<<30 ? -1 : ret;
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
			int width                 = 11;
			int height                = 3;
			int red[]                 = {5,5};
			int blue[]                = {2,5};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int width                 = 30;
			int height                = 5;
			int red[]                 = {4,10,7,8,10};
			int blue[]                = {5,6,11,7,5};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int width                 = 16;
			int height                = 4;
			int red[]                 = {6,5,7};
			int blue[]                = {5};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int width                 = 4;
			int height                = 4;
			int red[]                 = {5};
			int blue[]                = {6};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int width                 = 6;
			int height                = 2;
			int red[]                 = {6,6};
			int blue[]                = {2};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
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
