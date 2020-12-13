/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

int main() {

    int N;
    char S[1000];
    scanf("%d ", &N);
    while (N--) {
        gets(S);
        stack<int> P;
        bool ok = true;
        for (int i = 0; S[i] && ok; i++) {
            if (S[i]=='(' || S[i]=='[') P.push(S[i]);
            else if (S[i]==')') {
                if (P.empty() || P.top()!='(') ok = false;
                else P.pop();
            }
            else if (S[i]==']') {
                if (P.empty() || P.top()!='[') ok = false;
                else P.pop();
            }
        }
        if (ok && P.empty()) puts("Yes");
        else puts("No");
    }

    return 0;
}
