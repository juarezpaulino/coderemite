/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// BEGIN CUT HERE

// END CUT HERE
#line 5 "ParkAmusement.cpp"
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
vector<string> L;
double DP[55][55];
bool done[55][55];

double go(int u, int k) {
    double &ret = DP[u][k];
    if (done[u][k]) return ret;
    done[u][k] = 1;
    ret = 0;
    if (k == 0) {
        if (L[u][u]=='E') ret = 1.;
        return ret;
    }
    int c = 0;
    for (int i = 0; i < N; i++) if (L[u][i]=='1') {
        ret += go(i,k-1);
        c++;
    }
    if (c) ret /= c;
    return ret;
}

class ParkAmusement {
public:
    double getProbability( vector <string> landings, int startLanding, int K ) {
        L = landings; N = L.size();
        memset(done,0,sizeof(done));
        double tot = 0.;
        for (int i = 0; i < N; i++) tot += go(i,K);
        return  DP[startLanding][K] / (double) tot;
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

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string landings[]         = {"E000",
 "1000",
 "1000",
 "1000"};
			int startLanding          = 1;
			int K                     = 1;
			double expected__         = 0.3333333333333333;

			clock_t start__           = clock();
			double received__         = ParkAmusement().getProbability(vector <string>(landings, landings + (sizeof landings / sizeof landings[0])), startLanding, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string landings[]         = {"E000",
 "1000",
 "1001",
 "000P"};
			int startLanding          = 1;
			int K                     = 1;
			double expected__         = 0.6666666666666666;

			clock_t start__           = clock();
			double received__         = ParkAmusement().getProbability(vector <string>(landings, landings + (sizeof landings / sizeof landings[0])), startLanding, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string landings[]         = {"01000100",
 "00111000",
 "00001010",
 "000E0000",
 "0000E000",
 "00000P00",
 "000000P0",
 "01000000"};
			int startLanding          = 1;
			int K                     = 2;
			double expected__         = 0.14285714285714288;

			clock_t start__           = clock();
			double received__         = ParkAmusement().getProbability(vector <string>(landings, landings + (sizeof landings / sizeof landings[0])), startLanding, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string landings[]         = {"0100",
 "0010",
 "0001",
 "000E"};
			int startLanding          = 0;
			int K                     = 2;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = ParkAmusement().getProbability(vector <string>(landings, landings + (sizeof landings / sizeof landings[0])), startLanding, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string landings[]         = {"E00",
 "0E0",
 "010"};
			int startLanding          = 0;
			int K                     = 1;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = ParkAmusement().getProbability(vector <string>(landings, landings + (sizeof landings / sizeof landings[0])), startLanding, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string landings[]         = {"01000000000100000010010000000100000100000100000000", "00000100000000000000000000000000000100000000000000", "01000010000100000010000000000100000100010100010000", "01000100010001011010001100110100110110011010000000", "01110111000110101011010111101000001010000000001100", "00000P00000000000000000000000000000000000000000000", "000000P0000000000000000000000000000000000000000000", "10010010010100011000110100110100100010000101010000", "11101111010111100001110001111001101010111001101101", "01100010000000000010010100100000010000010110010000", "11110111010000011000011000110110100100011011000001", "01000010000000000010010100000100000000000100000000", "01010101010001001011110001111010000111000111111000", "10100110010100000010010000010100010100001100010000", "01100111010101011011100011011110110011001111011000", "11000000000001000000011100110000010000001110000000", "11100110010101000010111000100100010110000110000001", "01100111001101111011110111111000110010001110011101", "01000100000000000000010000000000000100000000000000", "01110111001101001000111010011110010111000111011000", "11000010000000010010000100110000110100001001000001", "000000000000000000000E0000000000000000000000000000", "01100110010001000000010000100100010100001110010000", "00000000000000000000000P00000000000000000000000000", "10000110011101010000001100111110000110001100000001", "01000110010100000000011010001010010111011010000001", "11100100000100000000010100000100000100010100010000", "11100010010000000000010000100100010100011100000000", "00110011011001010010101100110110110010011110011000", "01000010000000000010000000000000000100000100000000", "10110101000101001000011000010000110000000110010001", "11111111000110011110111011100110000010111100111001", "11000100000001010000000100110100000010011111010001", "01000110000000000010010000100000000000001111000000", "11110110010101101011011110100100110110001111011000", "00000000000000000000000000000000000E00000000000000", "11100110000100000000011100010100010100011100000001", "11100110001000011010111110100100010100001010011001", "11110111011011111001101011001100110011001100000100", "000000000000000000000000000000000000000E0000000000", "11100010000100000000010000100100000100010100010000", "00000000000000000000000000000000000000000E00000000", "11100010000100000000010000100100000100011000000000", "11100110000100000000000100100000000100011010010000", "10110010010001111111011111111110011110000111011101", "10000110000100000000000100000000000100010100000000", "10110011001101001010011000110110010010010001010001", "10000100010101111010111101001110101101011010011001", "10001101111100011011111100001110011111011101111001", "00100010000000010010001100010100010100010111010000"};
			int startLanding          = 4;
			int K                     = 28;
			double expected__         = 0.0025;

			clock_t start__           = clock();
			double received__         = ParkAmusement().getProbability(vector <string>(landings, landings + (sizeof landings / sizeof landings[0])), startLanding, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string landings[]         = ;
			int startLanding          = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ParkAmusement().getProbability(vector <string>(landings, landings + (sizeof landings / sizeof landings[0])), startLanding, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string landings[]         = ;
			int startLanding          = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ParkAmusement().getProbability(vector <string>(landings, landings + (sizeof landings / sizeof landings[0])), startLanding, K);
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
