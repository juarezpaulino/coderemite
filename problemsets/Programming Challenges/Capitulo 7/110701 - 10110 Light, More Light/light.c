/* Light, More Light */

#include <stdio.h>
#include <math.h>

int main() {
    
    unsigned bulb;
    float root;
    
    while (scanf("%u", &bulb)) {
        
        if (bulb == 0)
            break;
        
        root = sqrt(bulb);
        if (bulb == root * root)
            printf("yes\n");
        else
            printf("no\n");
    }
    
    return 0;
}
