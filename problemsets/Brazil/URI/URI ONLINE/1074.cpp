/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 0) puts("NULL");
        else if (x < 0 && x%2) puts("ODD NEGATIVE");
        else if (x > 0 && x%2) puts("ODD POSITIVE");
        else if (x < 0 && x%2==0) puts("EVEN NEGATIVE");
        else if (x > 0 && x%2==0) puts("EVEN POSITIVE");
    }

    return 0;
}
