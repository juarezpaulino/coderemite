/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

const int NUM[] = {137, 1315, 73, 136, 255, 1384, 16385, 0};

void print(int N) {
    int e, p;
    for (e = 0, p = 1; 2*p <= N; e++, p*=2);
    if (e == 0) { printf("2(0)"); return; }
    printf("2");
    if (e > 1){ printf("("); print(e); printf(")"); }
    N-=p;
    if (N) { printf("+"); print(N); }
}

int main() {

    freopen("OUT.txt", "w", stdout);

    for (int i = 0; NUM[i]; i++) {
        printf("%d=", NUM[i]);
        print(NUM[i]);
        putchar('\n');
    }

    return 0;
}
