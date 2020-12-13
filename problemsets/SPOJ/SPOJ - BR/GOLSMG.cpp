/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <deque>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<short,int> PII;

int E, P, J, T;
short V[1010101];

int compute() {
    int ret = 0;
    deque<PII> MAX, MIN;
    for (int i = 0; i < J; i++) {
        int v = V[i];
        while (!MAX.empty() && v >= MAX.back().first) MAX.pop_back(); MAX.push_back(PII(v,i));
        while (!MIN.empty() && v <= MIN.back().first) MIN.pop_back(); MIN.push_back(PII(v,i));
    }
    int i = J;
    while (1) {
        ret += MAX.front().first + MIN.front().first;
        if (i == P) break;
        while (!MAX.empty() && i-MAX.front().second+1 > J) MAX.pop_front();
        while (!MIN.empty() && i-MIN.front().second+1 > J) MIN.pop_front();
        int v = V[i];
        while (!MAX.empty() && v >= MAX.back().first) MAX.pop_back(); MAX.push_back(PII(v,i));
        while (!MIN.empty() && v <= MIN.back().first) MIN.pop_back(); MIN.push_back(PII(v,i));
        i++;
    }
    return ret;
}


int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &E, &P, &J);
        string ret;
        int r = -1;
        for (int i = 0; i < E; i++) {
            char S[100];
            scanf("%s", S);
            for (int j = 0; j < P; j++) scanf("%d", V+j);
            int tot = compute();
            if (tot > r || (tot == r && string(S) < ret)) ret = S, r = tot;
        }
        printf("%s %d\n", ret.c_str(), r);
    }

    return 0;
}
