/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "ProductTriplet.cpp"
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

class ProductTriplet {
public:
    long long f(long long x0, long long y1, long long y2, long long z1, long long z2) {
        z1 = max(z1, x0*x0+1);
        if (z2 < z1) return 0;
        y1 = max(y1, (z1+x0-1)/x0);
        y2 = min(y2, z2/x0);
        return max(0LL,y2-y1+1);
    }
    long long countTriplets( int minx, int maxx, int miny, int maxy, int minz, int maxz ) {
        long long x1 = minx, x2 = maxx, y1 = miny, y2 = maxy, z1 = minz, z2 = maxz;
        long long ret = 0;
        for (long long x0 = x1; x0*x0 < z2 && x0 <= x2; x0++)
            ret += f(x0,y1,y2,z1,z2);
        for (long long y0 = y1; y0*y0 < z2 && y0 <= y2; y0++)
            ret += f(y0,x1,x2,z1,z2);
        for (long long sq = max(x1,y1); sq <= min(x2,y2) && sq*sq <= z2; sq++)
            if (sq*sq >= z1) ret++;
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
			int minx                  = 2;
			int maxx                  = 2;
			int miny                  = 3;
			int maxy                  = 3;
			int minz                  = 6;
			int maxz                  = 6;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int minx                  = 2;
			int maxx                  = 2;
			int miny                  = 3;
			int maxy                  = 3;
			int minz                  = 7;
			int maxz                  = 7;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int minx                  = 6;
			int maxx                  = 8;
			int miny                  = 4;
			int maxy                  = 5;
			int minz                  = 27;
			int maxz                  = 35;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int minx                  = 1;
			int maxx                  = 458;
			int miny                  = 1;
			int maxy                  = 458;
			int minz                  = 1;
			int maxz                  = 458;
			long long expected__      = 2877;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int minx                  = 8176;
			int maxx                  = 184561;
			int miny                  = 1348;
			int maxy                  = 43168;
			int minz                  = 45814517;
			int maxz                  = 957843164;
			long long expected__      = 2365846085LL;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int minx                  = ;
			int maxx                  = ;
			int miny                  = ;
			int maxy                  = ;
			int minz                  = ;
			int maxz                  = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int minx                  = ;
			int maxx                  = ;
			int miny                  = ;
			int maxy                  = ;
			int minz                  = ;
			int maxz                  = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int minx                  = ;
			int maxx                  = ;
			int miny                  = ;
			int maxy                  = ;
			int minz                  = ;
			int maxz                  = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
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
