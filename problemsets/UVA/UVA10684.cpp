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

using namespace std;

int V[10000], N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        int ret = 0, t = 0;
        for (int i = 0; i < N; i++) {
            t += V[i];
            if (t < 0) t = 0;
            ret = max(ret, t);
        }
        if (ret == 0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", ret);
    }

    return 0;
}
