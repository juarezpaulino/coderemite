/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
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

char sol[] = "123456789";

int main() {

    queue<string> q;
    q.push(sol);
    hash_map<string,int> D;
    hash_map<string,string> P;
    hash_map<string,string> S;
    D[sol] = 0;
    while (!q.empty()) {
        string u = q.front(); q.pop();
        int d = D[u];
        for (int i = 0; i < 3; i++) {
            string v = u;
            for (int j = 0; j < 3; j++) v[i*3+((j+2)%3)] = u[i*3+j];
            if (D.count(v)) continue;
            D[v] = d+1;
            P[v] = u;
            S[v] = "H" + string(1,'1'+i);
            q.push(v);
        }
        for (int j = 0; j < 3; j++) {
            string v = u;
            for (int i = 0; i < 3; i++) v[((i+1)%3)*3+j] = u[i*3+j];
            if (D.count(v)) continue;
            D[v] = d+1;
            P[v] = u;
            S[v] = "V" + string(1,'1'+j);
            q.push(v);
        }
    }

    string u(9,0);
    while (scanf(" %c ", &u[0]) != EOF) {
        if (u[0]=='0') break;
        for (int i = 1; i < 9; i++) scanf(" %c ", &u[i]);
        if (D.count(u)) {
            printf("%d ", D[u]);
            string ret = "";
            while (u != sol) {
                ret += S[u];
                u = P[u];
            }
            printf("%s\n", ret.c_str());
        }
        else puts("Not solvable");
    }


    return 0;
}
