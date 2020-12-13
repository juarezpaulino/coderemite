/* Wertyu */

#include <stdio.h>

char in[] = "1234567890-=WERTYUIOP[]\\SDFGHJKL;\'XCVBNM,./";

int search(char ch) {
    
    int i;
    for (i = 0; i < 43; i++)
        if  (ch == in[i])
            return (i);
    
    return -1;
}

int main() {

    char line[100];
    int i, pos;
    
    while (fgets(line, 100, stdin)) {
        
        for (i = 0; line[i] != '\n' && line[i] != EOF; i++) {
            if (line[i] == ' ')
                putchar(' ');
            else if (line[i] == '1')
                putchar('\'');
            else if (line[i] == 'W')
                putchar('Q');
            else if (line[i] == 'S')
                putchar('A');
            else if (line[i] == 'X')
                putchar('Z');
            else {
                pos = search(line[i]);
                putchar(in[pos - 1]);
            }
        }
        putchar('\n'); 
    }
    
    return 0;
}
