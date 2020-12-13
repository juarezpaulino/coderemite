/* Stacks of Flapjacks */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int diameter;
    int original;
} pancake;


pancake pancakes[32];
int diameters[32];
char flips[62];

int compare_diameter(const void *x, const void *y) {

    return(*(int *)y - *(int *)x);
}

int compare_original(const void *x, const void *y) {

    return(((pancake *)x) -> original - ((pancake *)y) -> original);
}

int search(int num, int size) {
    
    int i;
    
    for (i = 0; i < size; i++)
        if (pancakes[i].diameter == num)
            return i;
    
    return -1;
}

void flip(int num) {

    int i;
    pancake aux;
    
    for (i = 0; i <= num/2; i++) {
        aux = pancakes[0+i];
        pancakes[0+i] = pancakes[num-i];
        pancakes[num-i] = aux;
    }
}

int main() {

    int size, num;
    char ch;
    int i, pos, sort, num_flip;   
    
    size = 0;
    while (scanf("%d%c", &num, &ch) != EOF) {
        diameters[size] = pancakes[size].diameter = num;
        pancakes[size].original = size;
        size++;
        while (ch == ' ') {
            scanf("%d%c", &num, &ch);
            diameters[size] = pancakes[size].diameter = num;
            pancakes[size].original = size;
            size++;
        }
        
        qsort(diameters, size, sizeof(int), compare_diameter);
        
        for (i = 0, num_flip = 0, sort = size - 1; i < size; i++) {
            if ((pos = search(diameters[i], size)) != sort) {
                if (pos != 0) {
                    flip(pos);
                    flips[num_flip] = size - pos;
                    num_flip++;
                }
                flip(sort);
                flips[num_flip] = size - sort;
                num_flip++;
                sort--;
            }
            else
                sort--;
        }
        
        qsort(pancakes, size, sizeof(pancake), compare_original);
        
        for (i = 0; i < size; i++) {
            printf("%d", pancakes[i].diameter);
            if (i < size - 1)
                putchar(' ');
        }
        putchar('\n');
        
        for (i = 0; i < num_flip; i++)
            printf("%d ", flips[i]);
        putchar('0');
        putchar('\n');
        
        size = 0;
    }
    
    return 0;
}
