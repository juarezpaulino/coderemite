/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        double ret = 0;
        char c;
        while ((c = getchar()) == '\n' || c == ' ');
        while (c != '\n') {
            double v = (c == 'C') ? 12.01 : (c == 'H') ? 1.008 : (c == 'O') ? 16. : (c == 'N') ? 14.01 : 0.;
            int n = 0;
            while ((c = getchar()) >= '0' && c <= '9') n = n*10 + c - '0';
            if (!n) n = 1;
            ret += n*v;
        }
        printf("%.3lf\n", ret);
    }

    return 0;
}
