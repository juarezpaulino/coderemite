/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    for (double i = 1; i < 10; i+=2)
        for (int j = i+6, k = 0; k < 3; j--, k++) printf("I=%d J=%d\n", i, j);

    return 0;
}
