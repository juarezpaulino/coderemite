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
#include <cstring>

using namespace std;

char P[1010][1010];

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}

int main() {

char mask[15][64] = {
".***.. ****.. .****. ****.. *****. *****. .****. *...*. *****.",
"*...*. *...*. *...*. *...*. *..... *..... *..... *...*. ..*...",
"*****. ****.. *..... *...*. ***... ***... *..**. *****. ..*...",
"*...*. *...*. *..... *...*. *..... *..... *...*. *...*. ..*...",
"*...*. ****.. .****. ****.. *****. *..... .***.. *...*. *****.",
"..***. *...*. *..... *...*. *...*. .***.. ****.. .***.. ****..",
"...*.. *..*.. *..... **.**. **..*. *...*. *...*. *...*. *...*.",
"...*.. ***... *..... *.*.*. *.*.*. *...*. ****.. *...*. ****..",
"*..*.. *..*.. *..... *...*. *..**. *...*. *..... *..**. *..*..",
".**... *...*. *****. *...*. *...*. .***.. *..... .****. *...*.",
".****. *****. *...*. *...*. *...*. *...*. *...*. *****. ......",
"*..... *.*.*. *...*. *...*. *...*. .*.*.. .*.*.. ...*.. ......",
".***.. ..*... *...*. .*.*.. *.*.*. ..*... ..*... ..*... ......",
"....*. ..*... *...*. .*.*.. **.**. .*.*.. ..*... .*.... ......",
"****.. .***.. .***.. ..*... *...*. *...*. ..*... *****. ......"
};


    char I[1010], O[100];
    for (int i = 0; i < 60; i++) for (int j = 0; j < 60; j++) P[500+i][500+j] = '.';
    while (gets(I)) {
        bool c5 = 0;
        int m = 1;
        int r = 0, c = 0;
        vector<string> T = tokenize(I, " ");
        if (T[0] == ".EOP") {
            for (int i = 0; i < 60; i++, putchar('\n')) for (int j = 0; j < 60; j++) putchar(P[500+i][500+j]);
            putchar('\n'); for (int j = 0; j< 60; j++) putchar('-'); putchar('\n'); putchar('\n');
            for (int i = 0; i < 60; i++) for (int j = 0; j < 60; j++) P[500+i][500+j] = '.';
            continue;
        }
        if (T[1] == "C5") c5 = 1, m = 6;
        int k = 0, l = 0;
        for (; I[k] != '|'; k++);
        for (k++; I[k] != '|'; k++) O[l++] = I[k];
        O[l] = 0;
        if (T[0] == ".C") { sscanf(T[2].c_str(), "%d", &r); r--; r += 500; c = 530-(m*l/2); }
        if (T[0] == ".L") { sscanf(T[2].c_str(), "%d", &r); r--; r += 500; c = 500; }
        if (T[0] == ".R") { sscanf(T[2].c_str(), "%d", &r); r--; r += 500; c = 560-m*l; }
        if (T[0] == ".P") { sscanf(T[2].c_str(), "%d", &r); r--; r += 500; sscanf(T[3].c_str(), "%d", &c); c--; c += 500; }
        if (c5) {
            for (int i = 0; O[i]; i++, c+=6) {
                if (O[i]==' ') continue;
                int p = O[i]-'A';
                int y = p/9, x = p%9;
                for (int k = 0; k < 5; k++) for (int j = 0; j < 6; j++) if (mask[y*5+k][x*7+j]=='*') P[r+k][c+j] = '*';
            }
        }
        else for (int i = 0; O[i]; i++, c++) if (O[i]!=' ') P[r][c] = O[i];
    }

    return 0;
}
