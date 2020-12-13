/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>

using namespace std;

int main() {

    int N;
    map<int,int> cubes;
    for (int i = 1, y; (y = i*i*i) < 1000000; i++) cubes.insert(make_pair(y,i));
    while (scanf("%d", &N)) {
        if (N == 0) break;
        bool ok = 0;
        for (int i = 1, y; (y = i*i*i) < 1000000; i++) {
            int x = N+y;
            if (cubes.count(x)) {
                printf("%d %d\n", cubes[x], i);
                ok = 1;
                break;
            }
        }
        if (!ok) puts("No solution");
    }

    return 0;
}
