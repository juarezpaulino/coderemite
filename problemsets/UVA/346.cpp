/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

map<string,int> C;

int main() {

    C["A"] = 0;
    C["A#"] = 1;
    C["BB"] = 1;
    C["B"] = 2;
    C["B#"] = 3;
    C["CB"] = 2;
    C["C"] = 3;
    C["C#"] = 4;
    C["DB"] = 4;
    C["D"] = 5;
    C["D#"] = 6;
    C["EB"] = 6;
    C["E"] = 7;
    C["E#"] = 8;
    C["FB"] = 7;
    C["F"] = 8;
    C["F#"] = 9;
    C["GB"] = 9;
    C["G"] = 10;
    C["G#"] = 11;
    C["AB"] = 11;

    char S[1010];
    while (gets(S)) {
        char a[10], b[10], c[10];
        sscanf(S, "%s %s %s", a, b, c);
        string v[3] = {a, b, c};
        for (int i = 0; i < 3; i++) transform(v[i].begin(), v[i].end(), v[i].begin(), ::toupper);
        pair<int,string> u[] = {make_pair(C[v[0]],v[0]), make_pair(C[v[1]],v[1]), make_pair(C[v[2]],v[2])};
        sort(u, u+3);
        int major = 0;
        string ret = "";
        for (int i = 0; i < 3; i++) {
            int j = (i+1)%3, k = (j+1)%3;
            if ((u[j].first-u[i].first+12)%12 == 4 && (u[k].first-u[j].first+12)%12 == 3) { major = 1; ret = u[i].second; break; }
            if ((u[j].first-u[i].first+12)%12 == 3 && (u[k].first-u[j].first+12)%12 == 4) { major = 2; ret = u[i].second; break; }
        }
        if (ret.size() == 2) {
            if (ret[1] == 'B') {
                if (ret[0]=='C') ret = "B";
                else if (ret[0]=='F') ret = "E";
                else {
                    if (ret[0]=='A') ret[0] = 'G';
                    else if (ret[0]=='B') ret[0] = 'A';
                    else if (ret[0]=='D') ret[0] = 'C';
                    else if (ret[0]=='E') ret[0] = 'D';
                    else if (ret[0]=='G') ret[0] = 'F';
                    ret[1] = '#';
                }
            }
            else if (ret[1]=='#') {
                if (ret[0]=='E') ret = "F";
                else if (ret[0]=='B') ret = "C";
            }
        }
        if (!major) printf("%s is unrecognized.\n", S);
        else if (major == 1) printf("%s is a %s Major chord.\n", S, ret.c_str());
        else printf("%s is a %s Minor chord.\n", S, ret.c_str());
    }

    return 0;
}
