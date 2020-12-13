/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>

using namespace std;

map<char,char> M;

int main() {

	M['S'] = 'B';
	M['B'] = 'S';
	M['C'] = 'F';
	M['F'] = 'C';
	char S[303], P[303];
	int np;
	while (gets(S)) {
		np = 0;
		int ret = 0;
		for (int i = 0; S[i]; i++) {
			if (np > 0 && P[np-1]==M[S[i]]) ret++, np--;
			else P[np++] = S[i];
		}
		printf("%d\n", ret);
	}

	return 0;
}
