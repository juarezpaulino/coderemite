/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}

typedef pair<double,int> pii;

int main() {

    char S[1010];
    while (gets(S)) {
        if (S == string("-")) break;
        double t = 0., T = 0.;
        while (1) {
            if (S == string("-")) break;
            vector<string> A = tokenize(S, " ");
            pii V[5];
            int b = 0, d = 0;
            for (int i = 0; i < 5; i++) {
                int u; char c;
                sscanf(A[i].c_str(), "%d%c", &u, &c);
                if (c == '%') {
                    d += u;
                    V[i] = make_pair(u, 0);
                }
                else if (c == 'g') {
                    if (i == 0) u *= 9;
                    else if (i==1 || i==2 || i==3) u *= 4;
                    else if (i==4) u *= 7;
                    V[i] = make_pair(u, 1);
                    b += u;
                }
                else {
                    V[i] = make_pair(u, 1);
                    b += u;
                }
            }
            d = 100-d;
            for (int i = 0; i < 5; i++) {
                if (!V[i].second) V[i].first *= (double)b / d;
                T += V[i].first;
                if (!i) t += V[i].first;
            }
            gets(S);
        }
        printf("%.0lf%%\n", t*100./T);
    }


    return 0;
}
