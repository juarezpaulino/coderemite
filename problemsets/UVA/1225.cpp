/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

vector<int> count_units(int N) {
    vector<int> ret(10, 0);
    for (int i = 0; i < 10; i++) ret[i] += N/10;
    for (int i = 1; i <= N%10; i++) ret[i]++;
    return ret;
}

vector<int> count_pow10(int N, int p) {
    vector<int> ret;
    ret = count_units(N/p - 1);
    for (int i = 0; i < 10; i++) ret[i] *= p;
    int last = (N/p)%10;
    ret[last] += (N%p) + 1;
    return ret;
}

vector<int> count_digits(int N) {
    vector<int> ret(10, 0);
    for (int p = 1; p <= N; p*=10) {
        vector<int> aux = count_pow10(N, p);
        for (int i = 0; i < 10; i++) ret[i] += aux[i];
    }
    return ret;
}


int main() {

    int N;
    scanf("%d", &N);
	while (N--) {
	    int A;
		scanf("%d", &A);
		vector<int> ret = count_digits(A);
		for (int i = 0; i < 9; i++) printf("%d ", ret[i]);
		printf("%d\n", ret[9]);
	}

	return 0;
}
