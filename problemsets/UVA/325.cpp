/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

string E;
int nE;
bool ok;

void exponent() {
    if (nE == E.size()) { ok = 0; return; }
    if (E[nE]=='+' || E[nE]=='-') {
        nE++;
        if (nE == E.size()) { ok = 0; return; }
    }
    if (!isdigit(E[nE])) { ok = 0; return; }
    while (nE < E.size() && isdigit(E[nE])) nE++;
    if (nE == E.size()) return;
    else { ok = 0; return; }
}

void real_constant() {
    if (nE == E.size()) { ok = 0; return; }
    if (E[nE]=='+' || E[nE]=='-') {
        nE++;
        if (nE == E.size()) { ok = 0; return; }
    }
    if (!isdigit(E[nE])) { ok = 0; return; }
    while (nE < E.size() && isdigit(E[nE])) nE++;
    if (nE == E.size()) { ok = 0; return; }
    if (E[nE]=='.') {
        nE++;
        if (nE == E.size()) { ok = 0; return; }
        if (!isdigit(E[nE])) { ok = 0; return; }
        while (nE < E.size() && isdigit(E[nE])) nE++;
        if (nE == E.size()) return;
    }
    if (E[nE]=='e' || E[nE]=='E') { nE++; exponent(); return; }
    else { ok = 0; return; }
}

int main() {

    while (cin >> E) {
        if (E=="*") break;
        ok = 1; nE = 0;
        real_constant();
        if (ok) printf("%s is legal.\n", E.c_str());
        else printf("%s is illegal.\n", E.c_str());
    }

    return 0;
}
