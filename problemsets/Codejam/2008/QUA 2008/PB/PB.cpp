/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXV = 300;

struct Trip { int s, t, d; };

bool cmp(const Trip &A, const Trip &B) { return A.s < B.s; }

Trip trip[MAXV];

int main() {
    
//	freopen("B.in","r",stdin);
//	freopen("B-small-practice.in","r",stdin);freopen("B-small-practice.out","w",stdout);
//	freopen("B-large-practice.in","r",stdin);freopen("B-large-practice.out","w",stdout);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {

        int TA, NA, NB;
        scanf("%d %d %d", &TA, &NA, &NB);
        for (int i = 0; i < NA; i++) {
            int sh, sm, th, tm;
            scanf("%d:%d %d:%d", &sh, &sm, &th, &tm);
            trip[i] = (Trip){sh*60+sm, th*60+tm, 0};
        }
        for (int i = 0; i < NB; i++) {
            int sh, sm, th, tm;
            scanf("%d:%d %d:%d", &sh, &sm, &th, &tm);
            trip[NA+i] = (Trip){sh*60+sm, th*60+tm, 1};
        }
        int N = NA+NB;
        
        sort(trip, trip+N, cmp);
        
        int ret[2] = {0, 0};
        priority_queue<int> TR[2];
        for (int i = 0; i < N; i++) {
            int d = trip[i].d;
            if (!TR[d].empty() && -TR[d].top() <= trip[i].s) TR[d].pop();
            else ret[d]++;
            TR[d^1].push(-(trip[i].t + TA));
        }

        printf("Case #%d: %d %d\n", t, ret[0], ret[1]);
    }

	return 0;
}
