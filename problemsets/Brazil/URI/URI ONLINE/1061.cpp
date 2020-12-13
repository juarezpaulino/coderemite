/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int a, h1, m1, s1;
    int b, h2, m2, s2;

    scanf("%*s %d %d : %d : %d", &a, &h1, &m1, &s1);
    scanf("%*s %d %d : %d : %d", &b, &h2, &m2, &s2);
    int c = a*86400+h1*3600+m1*60+s1;
    int d = b*86400+h2*3600+m2*60+s2;
    d = d - c;

    printf("%d dia(s)\n", d / 86400); d %= 86400;
    printf("%d hora(s)\n", d / 3600); d %= 3600;
    printf("%d minuto(s)\n", d / 60); d %= 60;
    printf("%d segundo(s)\n", d);

    return 0;
}
