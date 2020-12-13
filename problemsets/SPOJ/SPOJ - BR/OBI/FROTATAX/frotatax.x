#include <stdio.h>


int main() {
    float a, g, ka, kg;
    scanf("%f %f %f %f", &a, &g, &ka, &kg);
    if (a/ka < g/kg) puts("A");
    else puts("G");
    return 0;
}

