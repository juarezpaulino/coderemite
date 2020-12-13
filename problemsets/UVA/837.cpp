/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct event {
    double x, r;
    char b;
    bool operator<(const event &B) const {
        if (x != B.x) return x < B.x;
        if (b != B.b) return b < B.b;
        return r < B.r;
    }
};


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        vector<event> V(2*N, (event){0.,0.,0});
        for (int i = 0; i < N; i++) {
            double x1, x2, r;
            scanf("%lf %*lf %lf %*lf %lf", &x1, &x2, &r);
            V[i*2] = (event){x1, r, (x1 < x2)};
            V[i*2+1] = (event){x2, r, (x2 < x1)};
        }
        sort(V.begin(), V.end());
        vector<string> ret;
        double c = 1.;
        char s[20];
        for (int i = 0; i < V.size(); i++) {
            string r = "";
            if (i == 0) r += "-inf ";
            else { sprintf(s, "%.3lf ", V[i-1].x); r += s; }
            sprintf(s, "%.3lf ", V[i].x); r += s;
            sprintf(s, "%.3lf", c); r += s;
            ret.push_back(r);

            if (V[i].b) c *= V[i].r;
            else c /= V[i].r;
        }

        string r = "";
        sprintf(s, "%.3lf ", V[V.size()-1].x); r += s;
        r += "+inf 1.000";
        ret.push_back(r);

        printf("%d\n", ret.size());
        for (int i = 0; i < ret.size(); i++) printf("%s\n", ret[i].c_str());

        if (T) putchar('\n');
    }

    return 0;
}
