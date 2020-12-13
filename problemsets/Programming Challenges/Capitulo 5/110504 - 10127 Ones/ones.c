#include<stdio.h>
#include<math.h>

int main()
{

    unsigned int n;
    float a;
    unsigned int t;

    while(scanf("%u", &n) != EOF) {

        a = 1;
        t = 0;
        while(fmod(a,n)!=0) {
            a=(a*10)+1;
            a=fmod(a,n);
            t++;
        }

        printf("%u\n", t+1);
        n=0;
    }
    
    return 0;
}
