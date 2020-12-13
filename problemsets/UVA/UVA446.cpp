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
#include <algorithm>

using namespace std;

string binary(int A) {
    string ret;
    while (A) { ret += string(1,'0'+A%2); A/=2; }
    reverse(ret.begin(), ret.end());
    ret = string(13-ret.size(),'0') + ret;
    return ret;
}

int main() {

    int N;
    char A[10], B[10], op;
    scanf("%d", &N);
    while (N--) {
        scanf("%s %c %s", A, &op, B);
        int a = 0, b = 0;
        for (int i = 0; A[i]; i++) a = (a*16) + ((A[i]>='0'&&A[i]<='9') ? A[i]-'0' : A[i]-'A'+10);
        for (int i = 0; B[i]; i++) b = (b*16) + ((B[i]>='0'&&B[i]<='9') ? B[i]-'0' : B[i]-'A'+10);
        int C = (op=='+') ? a+b : a-b;
        printf("%s %c %s = %d\n", binary(a).c_str(), op, binary(b).c_str(), C);
    }

    return 0;
}
