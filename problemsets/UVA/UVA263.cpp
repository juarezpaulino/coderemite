/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include<ext/hash_map>
#include<ext/hash_set>

using namespace std;

using namespace __gnu_cxx;
namespace __gnu_cxx {
	template<> struct hash<string> {
		size_t operator()(const string& X) const {
			return hash<const char*>() (X.c_str());
		}
	};
}

int N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        hash_set<int> S;
        printf("Original number was %d\n", N);
        int ret = 0;
        while (1) {
            char A[15], B[15];
            sprintf(A, "%d", N);
            sprintf(B, "%d", N);
            sort(A, A+strlen(A));
            sort(B, B+strlen(B), greater<char>());
            int a = atoi(A),
                b = atoi(B);
            N = b-a;
            ret++;
            printf("%d - %d = %d\n", b, a, N);
            if (S.count(N)) break;
            S.insert(N);
        }
        printf("Chain length %d\n\n", ret);
    }

    return 0;
}
