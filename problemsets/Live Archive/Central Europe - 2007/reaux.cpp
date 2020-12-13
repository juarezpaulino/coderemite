/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define TLE while(1);
#define RTE printf("%d", 1/0);

using namespace std;
typedef vector<int> VI; typedef vector<double> VD; typedef vector<string> VS;
typedef vector<vector<int> > VVI; typedef vector<vector<string> > VVS;
typedef set<int> SI; typedef set<double> SD; typedef set<string> SS;
typedef pair<int,int> PII;
typedef signed long long i64; typedef unsigned long long u64;

#define EPS 1E-14
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


map<string, int> symb;

int main() {
    
    char n1[50], n2[50], j1[50], j2[50];
    int p1, p2, x, y, c = 1;
    
    symb["Kamen"]=0;
    symb["Rock"]=0;
    symb["Pierre"]=0;
    symb["Stein"]=0;
    symb["Ko"]=0;
    symb["Koe"]=0;
    symb["Sasso"]=0;
    symb["Roccia"]=0;
    symb["Guu"]=0;
    symb["Kamien"]=0;
    symb["Piedra"]=0;

    symb["Nuzky"]=1;
    symb["Scissors"]=1;
    symb["Ciseaux"]=1;
    symb["Schere"]=1;
    symb["Ollo"]=1;
    symb["Olloo"]=1;
    symb["Forbice"]=1;
    symb["Choki"]=1;
    symb["Nozyce"]=1;
    symb["Tijera"]=1;

    symb["Papir"]=2;
    symb["Paper"]=2;
    symb["Feuille"]=2;
    symb["Papier"]=2;
    symb["Papir"]=2;
    symb["Carta"]=2;
    symb["Rete"]=2;
    symb["Paa"]=2;
    symb["Papier"]=2;
    symb["Papel"]=2;

    while (1) {
        scanf("%*s %s", n1); scanf("%*s %s", n2); p1 = p2 = 0;
        while (scanf("%s", j1) && strcmp(j1, "-") && strcmp(j1, ".")) {
            scanf("%s", j2); x = symb[j1]; y = symb[j2];
            if (x!=y) ((x+1)%3==y) ? (p1++) : (p2++);
        }
        printf("Game #%d:\n", c++);
        printf("%s: %d %s\n", n1, p1, (p1==1)?"point":"points");
        printf("%s: %d %s\n", n2, p2, (p2==1)?"point":"points");
        if (p1==p2) printf("TIED GAME\n\n");
        else printf("WINNER: %s\n\n", (p1>p2)?n1:n2);
        if (!strcmp(j1, ".")) break;
    }
    
    return 0;
}
