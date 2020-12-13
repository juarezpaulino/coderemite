/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <string>

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


int main () {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        double m = 0., x;
        for (int i = 0; i < 12; i++) scanf("%lf", &x), m+=x;
        m /= 12.;
        printf("%d $", t);
        char S[110];
        sprintf(S, "%.2lf", m);
        vector<string> tok = tokenize(S, ".");
        long long a;
        sscanf(tok[0].c_str(), "%lld", &a);
        vector<int> ret;
        while (a) { ret.push_back(a%1000); a /= 1000; }
        if (tok[0]=="0") printf("0");
        for (int i = ret.size()-1; i >= 0; i--) {
            if (i < ret.size()-1) putchar(',');
            printf("%d", ret[i]);
        }
        printf(".%s\n", tok[1].c_str());
    }

    return 0;
}
