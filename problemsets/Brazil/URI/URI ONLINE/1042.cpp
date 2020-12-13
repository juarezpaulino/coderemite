/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int a, b, c;
    vector<int> v;
    scanf("%d %d %d", &a, &b, &c);
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", v[0], v[1], v[2], a, b, c);

    return 0;
}
