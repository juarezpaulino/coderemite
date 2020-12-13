/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main() {

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int d = (a+b+abs(a-b))/2;
    d = (d+c+abs(d-c))/2;
    printf("%d eh o maior\n", d);

    return 0;
}
