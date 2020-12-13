/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int X[123456], Y[123456];


int main() {

    int k = 1;
    X[k] = Y[k] = 0;
    for (int i = 1; k < 100001; i++) {
        for (int j = i-1; j >= 0; j--) { X[++k] = j; Y[k] = i-j; }
        for (int j = -1; j >= -i; j--) { X[++k] = j; Y[k] = i; }
        for (int j = i-1; j >= 0; j--) { X[++k] = -i; Y[k] = j; }
        for (int j = 1-i; j <= 0; j++) { X[++k] = j; Y[k] = -i-j; }
        for (int j = 1; j <= i; j++)   { X[++k] = j; Y[k] = -i; }
        for (int j = 1-i; j <= 0; j++) { X[++k] = i; Y[k] = j; }
    }

    while (scanf("%d", &k) != EOF) printf("%d %d\n", X[k], Y[k]);

    return 0;
}
