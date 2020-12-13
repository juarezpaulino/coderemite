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

    int a = 0, g = 0, d = 0;
    int x;
    while (scanf("%d", &x)) {
        if (x == 1) a++;
        else if (x == 2) g++;
        else if (x == 3) d++;
        else if (x == 4) break;
    }
    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", a, g, d);

    return 0;
}
