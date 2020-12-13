/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>


using namespace std;

int main() {

    int N, P;
    while (scanf("%d %d", &N, &P)) {
        if (!(N|P)) break;
        int l = N/P + (N%P!=0);
        if (l < 6) l = 0;
        else if (l > 20) l = 14;
        else l -= 6;
        printf("Poo");
        for (int i = 0; i < l; i++) putchar('o');
        printf("dle\n");
    }

    return 0;
}
