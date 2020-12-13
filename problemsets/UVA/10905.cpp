/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


bool comp(const string &A, const string &B) {
    if (A+B > B+A) return true;
    return false;
}

int main() {

    int N;
    string A[101];

    while (1) {
        scanf("%d", &N);
        if (!N) break;
        for (int i = 0; i < N; i++) cin >> A[i];
        sort(A, A+N, comp);
        for (int i = 0; i < N; i++) cout << A[i];
        cout << endl;
    }

    return 0;
}
