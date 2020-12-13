/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

int M[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string wday[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int d, m;
        scanf("%d %d", &m, &d);
        int k = 0;
        for (int i = 0; i < m-1; i++) k+=M[i];
        k += d-1;
        k %= 7;
        printf("%s\n", wday[k].c_str());
    }

    return 0;
}
