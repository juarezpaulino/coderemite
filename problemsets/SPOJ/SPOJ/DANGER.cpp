/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>


using namespace std;

int main() {

    while (1) {
        int N;
        double IN;
        cin >> IN;
        N = IN+1E-10;
        if (N == 0) break;

        int ret = N;
        int k = 0;
        while (N) {
            int d = N%2; if (d == 0) ret -= 1<<k;
            N/=2;
            k++;
        }
        printf("%d\n", ret);
    }

    return 0;
}
