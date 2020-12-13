/* Fmt */

#include <stdio.h>
#include <string.h>

#define C

#ifdef C
typedef char bool;
#define TRUE 1
#define FALSE 0
#endif

#define LENGHT 72

char line[250], ch;
int c_line, c_word, i, pos;
bool empty_line, line_break, eliminated;

void newline() {
    
    if (c_word > LENGHT) {
        for (i = 0; i < c_word; i++)
            putchar(line[i]);
        putchar('\n');
        line[0] = ch;
        c_line = 1;
        line_break = TRUE;
        empty_line = TRUE;
        return;
    }
    if ((line_break) || (empty_line)) {
        if ((line_break) && (line[0] != '\n')) {
            for (pos = c_line-3; line[pos] == ' '; pos--);
            line[++pos] = '\n';
            line[++pos] = '\0';
            printf(line);
        }
        putchar('\n');
        c_line = 0;
        empty_line = TRUE;
    }
    
    line_break = TRUE;
    
    c_word = 0;
    
    if (eliminated)
        eliminated = FALSE;
}

void space() {
    
    if (c_word > LENGHT) {
        for (i = 0; i < c_word; i++)
            putchar(line[i]);
        putchar('\n');
        line[0] = ch;
        c_line = 1;
        empty_line = TRUE;
        return;
    }
    
    if (eliminated)
        c_line = 0;
    if (line_break) {
        line[c_line] = '\0';
        printf(line);
        line[0] = ' ';
        c_line = 1;
        empty_line = TRUE;
        line_break = FALSE;
    }
    
    c_word = 0;
}

void character() {

    c_word++;
    
    if (line_break) {
        line[c_line-1] = ' ';
        line_break = FALSE;
    }
    empty_line = FALSE;
    
    if (eliminated)
        eliminated = FALSE;
}

void housekeep(char ch) {

    if (ch == '\n')
        newline();
    else if (ch == ' ') {
        for (pos = c_line-1; line[pos] == ' '; pos--);
        line[++pos] = '\n';
        line[++pos] = '\0';
        printf(line);
        empty_line = eliminated = TRUE;
    }
    else {
        c_word++;
        for (pos = c_line-c_word-1; line[pos] == ' '; pos--);
        line[++pos] = '\n';
        line[++pos] = '\0';
        printf(line);
        for (i = 0; i < c_word; i++)
            line[i] = line[c_line-c_word+i];
        c_line = c_word;
    }
        
            
}


int main() {
    
    c_line = c_word = 0;
    line_break = empty_line = eliminated = FALSE;
    while ((ch = getchar()) != EOF) {
        
        line[c_line] = ch;
        c_line++;
        if ((c_line == LENGHT) && (c_word < LENGHT))
            housekeep(ch);
        else if (ch == '\n')
            newline();
        else if (ch == ' ')
            space();
        else
            character();
    }
    
    return 0;
}
