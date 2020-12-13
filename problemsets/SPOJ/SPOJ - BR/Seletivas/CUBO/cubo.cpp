/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <set>
#include <queue>


#define abs(a) ((a)<0 ? -(a) : (a))

using namespace std;


struct cubo {
    int x, y;
    int bx, by;
    int mv, ep;
};

int tx, ty;
char st[20][20];
int maxmv, maxep;
int r, c;


struct cmp {
    bool operator()(const cubo &a, const cubo &b) {
        if (a.y < b.y) return true; else if (a.y > b.y) return false;
        else if (a.x < b.x) return true; else if (a.x > b.x) return false;
        else if (a.by < b.by) return true; else if (a.by > b.by) return false;
        else if (a.bx < b.bx) return true; else return false;
    }
};

struct cmp_queue {
    bool operator()(const cubo &a, const cubo &b) {
        int d1 = abs(tx-a.bx) + abs(ty-a.by);
        int d2 = abs(tx-b.bx) + abs(ty-b.by);
        if (d1 < d2) return false; else if (d1 > d2) return true;
        else if (a.mv < b.mv) return false; else return true;
    }
};

priority_queue<cubo, vector<cubo>, cmp_queue> q;
set<cubo, cmp> hash;

void BFS() {

    cubo f, p;
    set<cubo>::iterator it;
    int d;

    while (!q.empty()) {
        f = q.top(); q.pop();
        it = hash.find(f); if (f.ep > it->ep) continue;
        if (f.bx == tx && f.by == ty) {
            if (f.ep < maxep) { maxep = f.ep; maxmv = f.mv; }
            else if (f.ep == maxep && f.mv < maxmv) maxmv = f.mv;
            continue;
        }
        
        d = abs(tx-f.bx) + abs(ty-f.by);
        if (f.ep+d >= maxep) continue;
        
        // Move up
        p = f; p.y--; p.mv++;
        if (p.bx == p.x && p.by == p.y) { p.by--; p.ep++; }
        if (p.y >= 0 && p.by >= 0 && st[p.y][p.x]=='.' && st[p.by][p.bx]=='.') {
            if ((it = hash.find(p))==hash.end()) { hash.insert(p); q.push(p); }
            else if (it->ep > p.ep) { hash.erase(it); hash.insert(p); q.push(p); }
        }
        
        // Move down
        p = f; p.y++; p.mv++;
        if (p.bx == p.x && p.by == p.y) { p.by++; p.ep++; }
        if (p.y < r && p.by < r && st[p.y][p.x]=='.' && st[p.by][p.bx]=='.') {
            if ((it = hash.find(p))==hash.end()) { hash.insert(p); q.push(p); }
            else if (it->ep > p.ep) { hash.erase(it); hash.insert(p); q.push(p); }
        }
        
        // Move left
        p = f; p.x--; p.mv++;
        if (p.bx == p.x && p.by == p.y) { p.bx--; p.ep++; }
        if (p.x >= 0 && p.bx >= 0 && st[p.y][p.x]=='.' && st[p.by][p.bx]=='.') {
            if ((it = hash.find(p))==hash.end()) { hash.insert(p); q.push(p); }
            else if (it->ep > p.ep) { hash.erase(it); hash.insert(p); q.push(p); }
        }
        
        // Move right
        p = f; p.x++; p.mv++;
        if (p.bx == p.x && p.by == p.y) { p.bx++; p.ep++; }
        if (p.x < c && p.bx < c && st[p.y][p.x]=='.' && st[p.by][p.bx]=='.') {
            if ((it = hash.find(p))==hash.end()) { hash.insert(p); q.push(p); }
            else if (it->ep > p.ep) { hash.erase(it); hash.insert(p); q.push(p); }
        }
    }    
}


int main() {

    cubo cb;
    char str[22];
    int k = 1;
    
    while (scanf("%d %d ", &r, &c)) {
        if (!r && !c) break;
        hash.clear();
        printf("Instancia %d\n", k++);
        
        for (int i = 0; i < r; i++) {
            gets(str);
            for (int j = 0; j < c; j++)
                if (str[j] == 'S') { cb.y = i; cb.x = j; st[i][j] = '.'; }
                else if (str[j] == 'B') { cb.by = i; cb.bx = j; st[i][j] = '.'; }
                else if (str[j] == 'T') { ty = i; tx = j; st[i][j] = '.'; }
                else st[i][j] = str[j];
        }
        maxmv = maxep = 0x3F3F3F3F;
        cb.mv = cb.ep = 0;
        hash.insert(cb);
        q.push(cb);
        BFS();
        
        if (maxep == 0x3F3F3F3F) printf("Impossivel\n\n");
        else printf("%d %d\n\n", maxmv, maxep);
    }    
    
    return 0;
}
