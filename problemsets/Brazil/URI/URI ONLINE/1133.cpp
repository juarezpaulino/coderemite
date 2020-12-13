/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {

    int x, y;
    scanf("%d %d", &x, &y);
    if (y < x) swap(x,y);
    for (int i = x+1; i < y; i++) if (i%5==2||i%5==3) printf("%d\n", i);

    return 0;
}
