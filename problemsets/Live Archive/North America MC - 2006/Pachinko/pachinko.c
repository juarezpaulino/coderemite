/* Pachinko */

#include <stdio.h>

char str[1000];


int right(int k) {

    int i;    
    
    for (i = k+1; str[i] != '\0'; i++) {
        if (str[i] == '.') return (1);
        else if (str[i] == '_') continue;
        else if (str[i] == '/') return (0);
        else if (str[i] == '\\') return (0);
        else if (str[i] == '|') return (0);
    }
    
    return (1);
}

int left(int k) {

    int i;    
    
    for (i = k-1; i >= 0; i--) {
        if (str[i] == '.') return (1);
        else if (str[i] == '_') continue;
        else if (str[i] == '/') return (0);
        else if (str[i] == '\\') return (0);
        else if (str[i] == '|') return (0);
    }
    
    return (1);
}


int main() {
    
    int i;
    int p;
    int c;
    
    while (scanf("%s ", str)) {
        
        if (str[0] == '#') break;
        
        p = 0; c = 0;
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] == '.') { c++; p = p+100; }
            else if (str[i] == '_') { c++; continue; }
            else if (str[i] == '/') { c++; if (left(i)) p = p+100; }
            else if (str[i] == '\\') { c++; if (right(i)) p = p+100; }
            else if (str[i] == '|') {
                c++;
                if (right(i)) p = p+50;
                if (left(i)) p = p+50;
            }
        }
        p = p/c;
        printf("%d\n", p);
    }
    
    return 0;
}
