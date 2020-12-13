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

    int N;
    char S[110];
    scanf("%d", &N);
    while (N--) {
        scanf("%s", S);
        int A = 0, B = 0;
        for (int i = 0; i < 3; i++) A = A*26+S[i]-'A';
        for (int i = 4; S[i]; i++) B = B*10+S[i]-'0';
        if (abs(A-B) <= 100) puts("nice");
        else puts("not nice");
    }

    return 0;
}
