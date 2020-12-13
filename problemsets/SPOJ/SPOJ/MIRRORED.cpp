/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

#define ALL(M) (M).begin(), (M).end()
#define SORT(M) sort(ALL(M))
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

using namespace std;

typedef vector<int> VI;

int main() {

    string S;
    puts("Ready");
    while (1) {
        getline(cin, S);
        if (S == "  ") break;
        if (S == "pq" || S == "qp" || S == "bd" || S == "db") puts("Mirrored pair");
        else puts("Ordinary pair");
    }
    return 0;
}
