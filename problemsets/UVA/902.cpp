/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>

using namespace std;

#include<ext/hash_map>
#include<ext/hash_set>
using namespace __gnu_cxx;
namespace __gnu_cxx {
	template<> struct hash<string> {
		size_t operator()(const string& X) const {
			return hash<const char*>() (X.c_str());
		}
	};
}

char S[9010101];

int main() {

    int N;
    while (scanf("%d %s", &N, S) != EOF) {
        hash_map<string,int> M;
        int R = 0;
        string ret;
        for (int i = N; ; i++) {
            char cr = S[i];
            S[i] = 0;
            int c = (++M[S+i-N]);
            if (c > R) R = c, ret = S+i-N;
            S[i] = cr;
            if (!S[i]) break;
        }
        printf("%s\n", ret.c_str());
    }

    return 0;
}
