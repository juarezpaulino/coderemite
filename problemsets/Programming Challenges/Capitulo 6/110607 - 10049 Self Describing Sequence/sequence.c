/* Self-Describing Sequence */

#include <stdio.h>

int range[673366];


int binary_search(int *key, int *min, int *max) {

    int pos = (*max + *min) / 2;
    
    if ((*key <= range[pos]) && (*key > range[pos-1]))
        return pos;
    if (*key > range[pos]) {
        *min = pos+1;
        return (binary_search(key, min, max));
    }
    else {
        *max = pos-1;
        return (binary_search(key, min, max));
    }
}

void build_range() {

    int num, min, max, key;
    int i, times, j;

    num = 11;
    range[1] = 1;
    range[2] = 3;
    range[3] = 5;
    range[4] = 8;
    range[5] = 11;
    i = 6;
    while (i < 673366) {
        min = (i/145) + 1;
        max = (i/2) + 1;
        key = i;
        times = binary_search(&key, &min, &max);
        num += times;
        range[i] = num;
        i++;
    }
}

int main() {
    
    int n, pos, min, max;
    
    build_range();
    while (1) {
        
        scanf("%d", &n);
        if (n == 0)
            break;
        
        min = 1;
        max = 673365;
        pos = binary_search(&n, &min, &max);
        
        printf("%d\n", pos);
    }
    
    return 0;
}
