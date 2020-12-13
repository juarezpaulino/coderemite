/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <list>
#include <map>

using namespace std;

struct data {
    int tam, p;
};


int main() {

    int C, N;
    while (scanf("%d %d",&C, &N) != EOF) {
        int ret = 0;
        list<data> L;
        map<int, list<data>::iterator > M;
        L.push_back((data){C,0});
        for (int i = 0; i < N; i++) {
            char c;
            int p, q;
            scanf(" %c %d", &c, &p);
            if (c == 'C') {
                scanf("%d", &q);
                list<data>::iterator it;
                for (it = L.begin(); it != L.end(); it++) {
                    if (it->p == 0 && it->tam >= q) {
                        M[p] = L.insert(it, (data){q,p});
                        it->tam -= q;
                        if (it->tam == 0) L.erase(it);
                        ret += 10;
                        break;
                    }
                }
            }
            else {
                int d = M[p]->tam;
                list<data>::iterator it = L.erase(M[p]),
                                     prev = it;
                --prev;
                if (it!=L.end() && it->p==0 && prev->p==0)
                    prev->tam += d + it->tam, L.erase(it);
                else if (it!=L.end() && it->p==0)
                    it->tam += d;
                else if (prev->p==0)
                    prev->tam += d;
                else
                    L.insert(it, (data){d,0});
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
