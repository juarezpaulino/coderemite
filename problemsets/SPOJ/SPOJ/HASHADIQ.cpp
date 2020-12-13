/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()


#ifdef VCC
#include<hash_map>
#include<hash_set>
using namespace stdext;
#else
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
#endif

struct STATE { int id; string fn, ln, bd, pn; };

STATE INFO[1000000];

hash_map<string, set<int> > FN, LN, BD, PN;
hash_map<int, int> ID;
int N;

char str[10000];

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}


int main() {

    while (gets(str)) {
        if (!str) continue;
        vector<string> IN = tokenize(str, " ");
        if (IN[0] == "add") {
            int id = atoi(IN[1].c_str());
            if (ID.count(id)) {
                printf("ID %d ja cadastrado.\n", id);
                continue;
            }
            ID[id] = N;
            INFO[N].fn = IN[2];
            INFO[N].ln = IN[3];
            INFO[N].bd = IN[4];
            INFO[N].pn = IN[5];
            FN[IN[2]].insert(id);
            LN[IN[3]].insert(id);
            BD[IN[4]].insert(id);
            PN[IN[5]].insert(id);
            N++;
        }
        else if (IN[0] == "del") {
            int id = atoi(IN[1].c_str());
            if (!ID.count(id)) {
                printf("ID %d nao existente.\n", id);
                continue;
            }
            int p = ID[id];
            FN[INFO[p].fn].erase(id);
            LN[INFO[p].ln].erase(id);
            BD[INFO[p].bd].erase(id);
            PN[INFO[p].pn].erase(id);
            if (N > 1) {
                INFO[p] = INFO[N-1];
                ID[INFO[p].id] = p;
            }
            ID.erase(id);
            N--;
            if (N > 1000000) printf("%d\n", 1/0);
        }
        else if (IN[0] == "info") {
            int id = atoi(IN[1].c_str());
            if (!ID.count(id)) {
                printf("ID %d nao existente.\n", id);
                continue;
            }
            int p = ID[id];
            printf("%s %s %s %s\n", INFO[p].fn.c_str(), INFO[p].ln.c_str(), INFO[p].bd.c_str(), INFO[p].pn.c_str());
        }
        else if (IN[0] == "query") {
            if (IN.size() <= 1) continue;
            set<int> S[2];
            S[0].clear(); int k = 0;
            if (IN[1].substr(0,2)=="fn") {
                S[k] = FN[IN[1].substr(3)];
                k = 1;
            }
            else if (IN[1].substr(0,2)=="ln") {
                S[k] = LN[IN[1].substr(3)];
                k = 1;
            }
            else if (IN[1].substr(0,2)=="bd") {
                S[k] = BD[IN[1].substr(3)];
                k = 1;
            }
            else if (IN[1].substr(0,2)=="pn") {
                S[k] = PN[IN[1].substr(3)];
                k = 1;
            }
            for (int i = 2; S[k^1].size() && i < (int)IN.size(); i++) {
                S[k].clear();
                if (IN[i].substr(0,2)=="fn") set_intersection(S[k^1].begin(), S[k^1].end(), FN[IN[i].substr(3)].begin(), FN[IN[i].substr(3)].end(), std::inserter(S[k], S[k].begin()));
                else if (IN[i].substr(0,2)=="ln") set_intersection(S[k^1].begin(), S[k^1].end(), LN[IN[i].substr(3)].begin(), LN[IN[i].substr(3)].end(), std::inserter(S[k], S[k].begin()));
                else if (IN[i].substr(0,2)=="bd") set_intersection(S[k^1].begin(), S[k^1].end(), BD[IN[i].substr(3)].begin(), BD[IN[i].substr(3)].end(), std::inserter(S[k], S[k].begin()));
                else if (IN[i].substr(0,2)=="pn") set_intersection(S[k^1].begin(), S[k^1].end(), PN[IN[i].substr(3)].begin(), PN[IN[i].substr(3)].end(), std::inserter(S[k], S[k].begin()));
                k ^= 1;
            }
            int v = 0;
            if (S[k^1].empty()) putchar('\n');
            else { FORIT(it, ALL(S[k^1])) { if (v == 1) putchar(' '); printf("%d", *it); v = 1; } putchar('\n'); }
        }
    }

    return 0;
}
