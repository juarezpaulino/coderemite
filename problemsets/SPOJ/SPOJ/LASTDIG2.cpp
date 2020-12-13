/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
using namespace std;
char F[10], R[10];
int POW(int A, long long B) {
    if (B==0) return 1;
    int ret = POW(A,B/2);
    ret = (ret*ret)%10;
    if (B&1) ret = (ret*A)%10;
    return ret;
}
int main() {
    int t; scanf("%d", &t);
    string S;
    long long B;
    while (t--) {
        cin >> S >> B;
        int A = S[S.size()-1] - '0';
        printf("%c\n", POW(A,B)+'0');
    }
    return 0;
}
