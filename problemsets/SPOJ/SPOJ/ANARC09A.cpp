/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <stack>

using namespace std;

char S[3000];

int main() {

    int id = 1;
    while (scanf("%s", S) != EOF) {
        if (*S == '-') break;
        stack<char> P;
        for (int i = 0; S[i]; i++) {
            if (S[i]=='}' && !P.empty() && P.top()=='{') P.pop();
            else P.push(S[i]);
        }
        int ret = 0;
        while (!P.empty()) {
            char c1 = P.top(); P.pop();
            char c2 = P.top(); P.pop();
            if (c1==c2) ret++;
            else ret+=2;
        }
        printf("%d. %d\n", id, ret);
        id++;
    }

    return 0;
}
