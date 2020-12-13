/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string E;
int nE;
bool ok;

void slump() {
    if (nE == E.size()) { ok = 0; return; }
    if (E[nE]!='D' && E[nE]!='E') { ok = 0; return; }
    nE++;

    if (nE == E.size()) { ok = 0; return; }
    if (E[nE]!='F') { ok = 0; return; }
    while (nE < E.size() && E[nE]=='F') nE++;

    if (nE == E.size()) { ok = 0; return; }
    if (E[nE]=='G') nE++;
    else if (E[nE]=='D' || E[nE]=='E') slump();
    else ok = 0;
}


void slimp() {
    if (nE == E.size()) { ok = 0; return; }
    if (E[nE]!='A') { ok = 0; return; }
    nE++;

    if (nE == E.size()) { ok = 0; return; }
    if (E[nE]=='H') { nE++; return; }
    else if (E[nE]=='B') {
        nE++;
        slimp();
        if (nE == E.size()) { ok = 0; return; }
        if (E[nE]=='C') { nE++; return; }
        else { ok = 0; return; }
    }
    else if (E[nE]=='D' || E[nE]=='E') {
        slump();
        if (nE == E.size()) { ok = 0; return; }
        if (E[nE]=='C') { nE++; return; }
        else { ok = 0; return; }
    }
    else { ok = 0; return; }
}

void slurpy() {
    slimp();
    slump();
    if (nE != E.size()) ok = 0;
}

int main() {

    int T;
    scanf("%d", &T);
    puts("SLURPYS OUTPUT");
    while (T--) {
        cin >> E;
        nE = 0;
        ok = 1;
        slurpy();
        if (ok) puts("YES");
        else puts("NO");
    }
    puts("END OF OUTPUT");

    return 0;
}
