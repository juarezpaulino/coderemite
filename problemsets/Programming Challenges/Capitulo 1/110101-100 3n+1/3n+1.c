#include <stdio.h>

#define MAXVETOR 100000
#define swap(a,b) a^=b^=a^=b

int n[MAXVETOR+1];

typedef enum {FALSE, TRUE} boolean;

boolean isOdd(long long int num){
    return(num%2 ? TRUE : FALSE);
       
}


long long int lenght(long long int num){
    
    if (num == 1) 
        return 1;
    else if (num <= MAXVETOR+1){
        if (*(n+num-1) != 0)
            return *(n+num-1);
        else {
            if (isOdd(num))
                    return(*(n+num-1) = 1 + lenght((3*num)+1));
            else
                return(*(n+num-1) = 1 + lenght(num/2));
        }
    }
    else {
        if (isOdd(num))
            return(1 + lenght((3*num)+1));
        else
            return(1 + lenght(num/2));
    
    }
}
                

int main(){
    
    int a, b, x, max, aux;
    boolean change;
        
    while (scanf("%d %d",&a, &b)!= EOF) {
        change = FALSE;
        max = 0;
        if (a > b){
            change = TRUE;
            swap(a,b);
        }
        x = a;
        while (x <= b) {
            if ((aux = lenght(x)) > max) 
                max = aux;
            x++;    
           
        }
        if (change)
            swap(a,b);
        printf("%d %d %d\n",a,b,max);
    }        
    
    return 0;
}
