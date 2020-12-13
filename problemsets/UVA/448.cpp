/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

char V[] = "0123456789ABCDEF";
char C[][25] = {"ADD","SUB","MUL","DIV","MOV","BREQ","BRLE","BRLS","BRGE","BRGR","BRNE","BR","AND","OR","XOR","NOT"};

char S[1010];
int k = 0;
bool fin = 0;

int value(char c) {
    for (int i = 0; V[i]; i++) if (c == V[i]) return i;
    return -1;
}

int readC() {
    if (!S[k]) { if (!gets(S)) return -1; k = 0; }
    return value(S[k++]);
}

int readOp() {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (!S[k]) { if (!gets(S)) return -1; k = 0; }
        ret <<= 4;
        ret |= value(S[k++]);
    }
    return ret;
}

string parseOp(int v) {
    char s[40];
    int t = v>>14;
    int a = v&((1<<14)-1);
    if (t == 0) { sprintf(s, "R%d", a); return s; }
    else if (t == 1) { sprintf(s, "$%d", a); return s; }
    else if (t == 2) { sprintf(s, "PC+%d", a); return s; }
    else if (t == 3) { sprintf(s, "%d", a); return s; }
    return "";
}


int main() {

    int c = -1;
    string a = "", b = "", d = "";
    while (1) {
        if ((c = readC()) == -1) break;
        if (c==15 || (c >= 5 && c <= 11)) {
            a = parseOp(readOp());
            printf("%s %s\n", C[c], a.c_str());
        }
        else if (c < 5) {
            a = parseOp(readOp());
            b = parseOp(readOp());
            printf("%s %s,%s\n", C[c], a.c_str(), b.c_str());
        }
        else {
            a = parseOp(readOp());
            b = parseOp(readOp());
            d = parseOp(readOp());
            printf("%s %s,%s,%s\n", C[c], a.c_str(), b.c_str(), d.c_str());
        }
    }

    return 0;
}
