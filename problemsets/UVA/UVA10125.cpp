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


int main() {

    int N;
    int V[1000];
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        sort(V, V+N);
        map<int,vector<pair<int,int> > > H;
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) if (V[i]&&V[j]) {
            vector<pair<int,int> > &s = H[V[i]+V[j]];
            if (s.size() > 3) continue;
            s.push_back(make_pair(V[i],V[j]));
        }
        bool found = false;
        int ret;
        for (int i = N-1; i >= 0; i--) for (int j = 0; j < N; j++) if (i != j)
            if (H.count(V[i]-V[j])) {
                vector<pair<int,int> > &v = H[V[i]-V[j]];
                bool ok = false;
                for (int k = 0; k < v.size(); k++)
                    if (V[i]!=v[k].first && V[i]!=v[k].second &&
                        V[j]!=v[k].first && V[j]!=v[k].second   ) {
                        ok = true;
                        break;
                    }
                if (ok) { ret = V[i]; found = true; goto OUT; }
            }
OUT:
        if (found) printf("%d\n", ret);
        else puts("no solution");
     }

    return 0;
}
