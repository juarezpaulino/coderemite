/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>

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


const int MAX_SET = 100001;
int up[MAX_SET];
void init(int n) { for (int i = 0; i < n; i++) up[i] = -1; }
int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }
bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}


int main() {

    int T; scanf("%d", &T);
    while (T--) {
        hash_map<string,int> M;
        int F; scanf("%d", &F);
        init(F+1);
        char A[101], B[101];
        for (int i = 0; i < F; i++) {
            scanf("%s %s", A, B);
            int x;
            int a = (M.count(A)) ? M[A] : (x = M.size(), M[A] = x);
            int b = (M.count(B)) ? M[B] : (x = M.size(), M[B] = x);
            join(a, b);
            printf("%d\n", abs(up[root(a)]));
        }
    }

    return 0;
}
