/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    int N, M;
    while (scanf("%d %d", &N, &M)) {
        if (!(N+M)) break;
        string ret = ".";
        int C[1010] = {0};
        int k = 1;
        while (N && !C[N]) {
            C[N] = k++;
            N *= 10;
            if (N >= M) ret += string(1,'0' + N/M), N %= M;
            else ret += "0";
        }
        for (int i = 0; i < ret.size(); i+=50) printf("%s\n", ret.substr(i, 50).c_str());
        if (!N) printf("This expansion terminates.\n\n");
        else printf("The last %d digits repeat forever.\n\n", k-C[N]);
    }

    return 0;
}
