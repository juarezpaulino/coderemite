/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <map>
#include <list>
#include <set>
#include <string>

using namespace std;

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()


_inline(int alpha)(char ch) { return ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')); }

int n, c;
char ctg[30][200];
int target[30];
map<string, int> pad;
int npad;
set<int>fit[1000];
bool in[1000];
int get[30];
list<int> found;


int main() {
    
    int i, j, x;
    int w;
    char str[200], word[200], ch;
    char comma;
    
    scanf("%d ", &n);
    while (n--) {
        pad.clear(); npad = 0;
        scanf("%d ", &c);
        for (i = 0; i < c; i++) {
            scanf("%s %d %d ", ctg[i], &w, &target[i]);
            for (j = 0; j < w; j++) {
                scanf("%s ", str);
                if (!pad.count(str)) { x = pad[str] = npad++; fit[x].clear(); }
                else x = pad[str];
                fit[x].insert(i);
            }
            get[i] = 0;
        }
        for (i = 0; i < npad; i++) in[i] = false;
        
        while (gets(str)) {
            i = 0; ch = *str;
            if (!ch) break;
            while (ch) {
                while (ch && !alpha(ch)) ch = str[++i];
                if (!ch) break;
                j = 0;
                while (ch && alpha(ch)) { word[j++] = ch; ch = str[++i]; }
                word[j] = 0; if (pad.count(word)) in[pad[word]] = true;
            }
        }
        
        for (i = 0; i < npad; i++) if (in[i])
            foreach(it, all(fit[i])) get[*it]++;
        
        found.clear();
        for (i = 0; i < c; i++) if (get[i] >= target[i]) found.push_back(i);
        
        if (!found.size()) { puts("SQF Problem"); continue; }
        comma = 0;
        foreach(it, all(found)) {
            if (comma) putchar(',');
            printf("%s", ctg[*it]);
            comma = 1;
        }
        putchar('\n');
    }
    
    return 0;
}
