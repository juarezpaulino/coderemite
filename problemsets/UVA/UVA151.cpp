/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <list>

using namespace std;

int josephus(int N, int K) {
    int last = 0;
    list<int> F;
    for (int i = 2; i <= N; i++) F.push_back(i);
    list<int>::iterator it = F.begin();
    while (!F.empty()) {
        last = *it;
        for (int i = 0; i < K-1; i++) {
            it++;
            if (it == F.end()) it = F.begin();
        }
        it = F.erase(it);
        if (it == F.end()) it = F.begin();
    }
    return last;
}

int josephus2(int N, int K) {
    list<int> F;
    for (int i = 1; i <= N; i++) F.push_back(i);
    while (F.size() > 1) {
        F.pop_front();
        for (int i = 1; i < K; i++) {
            F.push_back(F.front());
            F.pop_front();
        }
    }
    return F.front();
}


int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        int k;
        for (k = 1; ; k++)
            if (josephus(N,k) == 13)
                break;
        printf("%d\n", k);
    }

    return 0;
}
