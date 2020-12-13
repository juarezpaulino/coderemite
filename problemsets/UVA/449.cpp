/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

map<string,int> mapa;
char S[1010101];

char natural[12][10] = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};
char sharp[12][10] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
int escala[6] = { 2, 4, 5, 7, 9, 11 };

char interval[][15] = {"SECOND", "THIRD", "FOURTH", "FIFTH", "SIXTH", "SEVENTH", "OCTAVE"};
int findInterval(string v) { for (int i = 0; i < 7; i++) if (v == interval[i]) return i+1; return -1; }

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}

vector<string> buildScale(string u) {
    vector<string> ret;
    int c = mapa[u];
    ret.push_back(u);
    for (int i = 0; i < 6; i++) {
        int d = (c+escala[i])%12;
        string v = sharp[d];
        if (u[0]==v[0]) v = natural[d];
        if (u[0]==v[0]) v = "Cb";
        ret.push_back(v);
        u = v;
    }
    return ret;
}

int findScale(vector<string> &A, string u) {
    for (int i = 0; i < A.size(); i++) if (A[i]==u) return i;
    return -1;
}

int main() {

    mapa["C"] = 0; mapa["B#"] = 0;
    mapa["C#"] = 1; mapa["Db"] = 1;
    mapa["D"] = 2;
    mapa["D#"] = 3; mapa["Eb"] = 3;
    mapa["E"] = 4; mapa["Fb"] = 4;
    mapa["F"] = 5; mapa["E#"] = 5;
    mapa["F#"] = 6; mapa["Gb"] = 6;
    mapa["G"] = 7;
    mapa["G#"] = 8; mapa["Ab"] = 8;
    mapa["A"] = 9;
    mapa["A#"] = 10; mapa["Bb"] = 10;
    mapa["B"] = 11; mapa["Cb"] = 11;

    while (gets(S)) {
        char key[10];
        sscanf(S, " %s ", key);
        printf("Key of %s\n", key);
        vector<string> scale = buildScale(key);
//        for (int i = 0; i < scale.size(); i++) printf("%s ", scale[i].c_str());
//        putchar('\n');

        gets(S);
        vector<string> tok = tokenize(S, ";");
        for (int i = 0; i < tok.size(); i++) {
            char key2[10], A[10], B[10];
            sscanf(tok[i].c_str(), "%s %s %s", key2, A, B);
            int a = A==string("UP")?0:1;
            int j = findInterval(B);
            if (a) j = 7-j;
            int w = findScale(scale, key2);
            if (w==-1) {
                printf("%s: invalid note for this key\n", key2);
                continue;
            }
            string C = scale[(w+j)%7];
            printf("%s: %s %s > %s\n", key2, A, B, C.c_str());
        }
        putchar('\n');
    }

    return 0;
}
