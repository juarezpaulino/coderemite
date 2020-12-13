/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int D[20000];
multiset<int> H;


int main() {

    int N, M;
    while (scanf("%d %d", &N, &M)) {
        if (!(N|M)) break;
        for (int i = 0; i < N; i++) scanf("%d", &D[i]);
        H.clear();
        for (int i = 0; i < M; i++) {
            int x;
            scanf("%d", &x);
            H.insert(x);
        }
        int k = 0, ret = 0;
        if (M >= N) while (k < N) {
            multiset<int>::iterator it = H.lower_bound(D[k]);
            if (it == H.end()) break;
            ret += *it;
            H.erase(it);
            k++;
        }
        if (k < N) printf("Loowater is doomed!\n");
        else printf("%d\n", ret);
    }

    return 0;
}
