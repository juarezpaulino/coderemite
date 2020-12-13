#include <stdio.h>
#include <string.h>



int main() {

    char str[50], word[30];
    int k, i, j, m, g, t;
    
    scanf("%d ", &k);
    while (k--) {
        gets(str); m = g = t = 0;
        for (i = 0; str[i]; ) {
            while (str[i]==' ') i++;
            for (j = 0; str[i]!=' ' && str[i]!=0; j++, i++) word[j] = str[i];
            word[j] = 0;
            if (strstr(word, "machovisk")) m++;
            else if (strstr(word, "granaisk")) g++;
            else if (strstr(word, "tucu")) t++;
        }
        printf("%d %d %d\n", m, g, t);
    }
    
    return 0;
}
