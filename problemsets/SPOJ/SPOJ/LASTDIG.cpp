/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <cstdio>

using namespace std;

int POW(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a%10;
    int ret = POW(a,b/2);
    ret = (ret*ret)%10;
    if (b%2==0) return ret;
    return (a*ret)%10;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int d = POW(a,b);
        printf("%d\n", d);
    }

    return 0;
}
