/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#line 2 "JumpFurther.cpp"

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class JumpFurther {
	public:
	int furthest(int N, int badStep) {
		int s = 0;
		bool ok = 1;
		for (int i = 1; i <= N; i++) {
            s += i;
            if (s == badStep) ok = 0;
		}
		int ret = N*(1+N) / 2;
		return ok ? ret : ret-1;
	}
};

////////////////////////////////////////////////////////////////////////////////

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing JumpFurther (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415195710;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		JumpFurther _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int badStep = 2;
				_expected = 3;
				_received = _obj.furthest(N, badStep); break;
			}
			case 1:
			{
				int N = 2;
				int badStep = 1;
				_expected = 2;
				_received = _obj.furthest(N, badStep); break;
			}
			case 2:
			{
				int N = 3;
				int badStep = 3;
				_expected = 5;
				_received = _obj.furthest(N, badStep); break;
			}
			case 3:
			{
				int N = 1313;
				int badStep = 5858;
				_expected = 862641;
				_received = _obj.furthest(N, badStep); break;
			}
			case 4:
			{
				int N = 1;
				int badStep = 757065;
				_expected = 1;
				_received = _obj.furthest(N, badStep); break;
			}
			/*case 5:
			{
				int N = ;
				int badStep = ;
				_expected = ;
				_received = _obj.furthest(N, badStep); break;
			}*/
			/*case 6:
			{
				int N = ;
				int badStep = ;
				_expected = ;
				_received = _obj.furthest(N, badStep); break;
			}*/
			/*case 7:
			{
				int N = ;
				int badStep = ;
				_expected = ;
				_received = _obj.furthest(N, badStep); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
