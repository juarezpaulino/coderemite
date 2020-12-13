/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#line 2 "ThreeColorabilityEasy.cpp"

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class ThreeColorabilityEasy {
	public:
	string isColorable(vector <string> cells) {
		string a = cells[0], b = a;
		for (int i = 0; i < a.size(); i++) b[i] = (a[i]=='N' ? 'Z' : 'N');
		for (int i = 0; i < cells.size(); i++)
            if (cells[i] != a && cells[i] != b) return "No";
        return "Yes";
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
		cout << "Testing ThreeColorabilityEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415208016;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ThreeColorabilityEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cells[] = {"Z"};
				_expected = "Yes";
				_received = _obj.isColorable(vector <string>(cells, cells+sizeof(cells)/sizeof(string))); break;
			}
			case 1:
			{
				string cells[] = {"NZ"
				                 ,"NZ"};
				_expected = "Yes";
				_received = _obj.isColorable(vector <string>(cells, cells+sizeof(cells)/sizeof(string))); break;
			}
			case 2:
			{
				string cells[] = {"ZZZ"
				                 ,"ZNZ"};
				_expected = "No";
				_received = _obj.isColorable(vector <string>(cells, cells+sizeof(cells)/sizeof(string))); break;
			}
			case 3:
			{
				string cells[] = {"NZNZNNN"
				                 ,"NNZNNNZ"
				                 ,"NNNNZZZ"
				                 ,"ZZZNZZN"
				                 ,"ZZNZNNN"
				                 ,"NZZZZNN"
				                 ,"ZZZNZNN"};
				_expected = "No";
				_received = _obj.isColorable(vector <string>(cells, cells+sizeof(cells)/sizeof(string))); break;
			}
			case 4:
			{
				string cells[] = {"ZZZZ"
				                 ,"ZZZZ"
				                 ,"ZZZZ"};
				_expected = "Yes";
				_received = _obj.isColorable(vector <string>(cells, cells+sizeof(cells)/sizeof(string))); break;
			}
			/*case 5:
			{
				string cells[] = ;
				_expected = ;
				_received = _obj.isColorable(vector <string>(cells, cells+sizeof(cells)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string cells[] = ;
				_expected = ;
				_received = _obj.isColorable(vector <string>(cells, cells+sizeof(cells)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string cells[] = ;
				_expected = ;
				_received = _obj.isColorable(vector <string>(cells, cells+sizeof(cells)/sizeof(string))); break;
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
