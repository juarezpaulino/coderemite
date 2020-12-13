/* Fermat vs Pythagoras */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXP 300000
#define MAXN 1000000

typedef struct {
    int x;
    int y;
    int z;
} primitive;

primitive p[MAXP];
int total_p;

int min(int a, int b) {
    
    return (a < b ? a : b);
}

int compare(primitive *a, primitive *b) {
    
    return (a->z - b->z);
}

char relatively_prime(int a, int b) {
    
    if (a < b) a^=b^=a^=b;
    
    while (b > 0) {
        a %= b;
        a^=b^=a^=b;
    }
    
    return (a == 1);
}

int b_search(primitive p[], int key, int beg, int end) {

    int mid;
    
    if (beg > end) return (end);
    mid = (beg+end)/2;
    if (p[mid].z > key) return (b_search(p, key, beg, mid-1));
    else return (b_search(p, key, mid+1, end));
}


int main() {
    
    int r, s;
    int up, dw;
    int compare();
    char taken[MAXN+1];
    int n;
    int i, index, k, count;
    int kx, ky, kz;
    
    for (r = 1; r <= sqrt(MAXN); r++) {
        if (r % 2)
            dw = 2;
        else
            dw = 1;
        up = min(sqrt(MAXN-r*r), r-1);
        for (s = dw; s <= up; s+=2)
            if (relatively_prime(r, s)) {
                p[total_p].x = r*r-s*s;
                p[total_p].y = 2*r*s;
                p[total_p].z = r*r+s*s;
                total_p++;
            }
    }
    
    qsort(p, total_p, sizeof(primitive), compare);
    
    /*for (i = 0; i < total_p; i++)
        printf("Primitive %d: %d %d %d\n", i+1, p[i].x, p[i].y, p[i].z);
    printf("%d\n", total_p);
    return 0;*/
    
    while (scanf("%d", &n) != EOF) {
        
        if (n < 5)
            printf("0 %d\n", n);
        else {
            for (i = 0; i <= n; i++)
                taken[i] = 0;
            index = b_search(p, n, sqrt(n)-2, min(total_p-1, n));
            count = n;
            for (i = 0; i <= index; i++) {
                k = 1;
                while (k*p[i].z <= n) {
                    kx = k*p[i].x;
                    ky = k*p[i].y;
                    kz = k*p[i].z;
                    if (!taken[kx]) {
                        count--;
                        taken[kx] = 1;
                    }
                    if (!taken[ky]) {
                        count--;
                        taken[ky] = 1;
                    }
                    if (!taken[kz]) {
                        count--;
                        taken[kz] = 1;
                    }
                    k++;
                } 
            }
            printf("%d %d\n", index+1, count);
        }
    }
    
    return 0;
}
