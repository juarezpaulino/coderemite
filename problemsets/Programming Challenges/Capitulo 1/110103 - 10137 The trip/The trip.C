#include <stdio.h>

int students[1001];

int main()
{
    int maior, menor;
    int money, cents;
    int media;
    int n, i;
    
    scanf("%d", &n);
    while (n) {
        media = 0;
        
        for (i = 0; i < n; i++) {
            scanf("%d.%d", &money, &cents);
            money *= 100;
            media += *(students + i) = money + cents;
        }
        media /= n;
        
        maior = 0;
        menor = 0;
        for(i = 0; i < n; i++) {
            if (*(students + i) > media)
                maior += *(students + i) - (media + 1);
            if (*(students + i) < media)
                menor += media - *(students + i);
        }
        
        if (menor >= maior)
            printf("$%d.%02d\n", menor / 100, menor % 100);
        else
            printf("$%d.%02d\n", maior / 100, maior % 100);
        
        scanf("%d", &n);
    }
        
    return 0;    
}
