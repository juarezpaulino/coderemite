/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#line 102 "InsertZ.cpp"

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class InsertZ {
	public:
	string canTransform(string init, string goal) {
		int j = 0;
		for (int i = 0; i < goal.size(); i++) {
			if (goal[i] == 'z') continue;
			if (init[j++]!=goal[i]) return "No";
		}
		if (j != init.size()) return "No";
		return "Yes";
	}
};

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
		cout << "Testing InsertZ (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415195198;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		InsertZ _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string init = "fox";
				string goal = "fozx";
				_expected = "Yes";
				_received = _obj.canTransform(init, goal); break;
			}
			case 1:
			{
				string init = "fox";
				string goal = "zfzoxzz";
				_expected = "Yes";
				_received = _obj.canTransform(init, goal); break;
			}
			case 2:
			{
				string init = "foon";
				string goal = "foon";
				_expected = "Yes";
				_received = _obj.canTransform(init, goal); break;
			}
			case 3:
			{
				string init = "topcoder";
				string goal = "zopzoder";
				_expected = "No";
				_received = _obj.canTransform(init, goal); break;
			}
			case 4:
			{
				string init = "aaaaaaaaaa";
				string goal = "a";
				_expected = "No";
				_received = _obj.canTransform(init, goal); break;
			}
			case 5:
			{
				string init = "mvixrdnrpxowkasufnvxaq";
				string goal = "mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq";
				_expected = "Yes";
				_received = _obj.canTransform(init, goal); break;
			}
			case 6:
			{
				string init = "opdlfmvuicjsierjowdvnx";
				string goal = "zzopzdlfmvzuicjzzsizzeijzowvznxzz";
				_expected = "No";
				_received = _obj.canTransform(init, goal); break;
			}
			/*case 7:
			{
				string init = ;
				string goal = ;
				_expected = ;
				_received = _obj.canTransform(init, goal); break;
			}*/
			/*case 8:
			{
				string init = ;
				string goal = ;
				_expected = ;
				_received = _obj.canTransform(init, goal); break;
			}*/
			/*case 9:
			{
				string init = ;
				string goal = ;
				_expected = ;
				_received = _obj.canTransform(init, goal); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
