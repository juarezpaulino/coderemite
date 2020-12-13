#include <stdio.h>
#include <stdlib.h>

#define abs(x) (((x) < 0) ? -(x) : (x))


int main() {

    int absx, absy, min;
    int x1, x2, y1, y2;
    
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2)) {
        
        if (!x1 && !x2 && !y1 && !y2) break;
        
        absx = abs(x1-x2);
        absy = abs(y1-y2);
        
        if (!absx && !absy) { puts("0"); continue; }
        if (!absx || !absy || (absy == absx)) { puts("1"); continue; }
        puts("2");        
    }
    
    return 0;
}
