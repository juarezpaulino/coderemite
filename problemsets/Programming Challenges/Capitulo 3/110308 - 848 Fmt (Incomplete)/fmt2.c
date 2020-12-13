/* Fmt */

#include <stdio.h>
#include <string.h>

char ch, word[80];
int c_line, c_space,  c_character, c_newline;
int i;
char skip_space, keeping_word, break_line, last_space, empty_line;

void newline() {
    
    c_newline++;
    
    if (last_space)
        last_space = 0;
    
    if (skip_space)
        skip_space = 0;
    
    if (empty_line) {
        putchar('\n');
        c_space = 0;
    }
    
    if (*word != '\0') {
        if (c_space > 0) {
            if (!empty_line)
                for (i = 0; i < c_space; i++)
                    putchar(' ');
                c_space = 0;
        }
        /*if (break_line) {
            if (!empty_line)
                putchar(' ');
            break_line = 0;
        }*/
        word[c_character] = '\0';
        printf(word);
        *word = '\0';
        c_character = 0;
    }
    
    if (c_newline > 1) {
        for (i = 0; i < c_newline; i++)
            putchar('\n');
        empty_line = 1;
        c_newline = 0;
        c_line = 0;
    }
}

void space() {
    
    if (c_space > 0) {
        if (!empty_line) {
            for (i = 0; i < c_space; i++)
                putchar(' ');
            c_space = 0;
        }
    }
    
    if (!skip_space) {
        c_space++;
        
        if (c_newline == 1) {
            putchar('\n');
            empty_line = 1;
            c_newline = 0;
            /*c_line = 0;*/
        }
        
        if (*word != '\0') {
            if (break_line) {
                if (!empty_line)
                    putchar(' ');
                break_line = 0;
            }
            word[c_character] = '\0';
            printf(word);
            *word = '\0';
            c_character = 0;
            c_newline = 0;
        }
    }
    else
        c_line--;

}

void character() {

    c_character++;
    word[c_character - 1] = ch;

    if (empty_line)
        empty_line = 0;
        
    if (last_space)
        last_space = 0;
        
    if (skip_space)
        skip_space = 0;
    
    if (c_newline) {
        break_line = 1;
        c_newline = 0;
    }

}

void housekeep() {
    
    if ((ch == ' ') && (!keeping_word)) {
        if (!last_space) {
            space();
            c_line -= 1;
            last_space = 1;
        }
        else {
            c_space++;
            c_line -= c_space;
            last_space = 0;
        }
    }
    else if ((ch == '\n') && (!keeping_word)) {
        newline();
        putchar('\n');
        empty_line = 1;
        c_newline = 0;
        c_line = 0;
    }
    else {
        keeping_word = 1;
        if (c_line == 73) {        
            c_character++;
            word[c_character - 1] = ch;
            word[c_character] = '\0';
            putchar('\n');
            printf(word);
            *word = '\0';
            c_newline = 0;
            break_line = 0;
        }
        else {
            if ((ch == '\n') || (ch == ' ')) {
                c_line = c_character;
                if ((ch == '\n')) {
                    c_newline = 1;
                    c_line++;
                }
                if (ch == ' ') {
                    c_space = 1;
                    c_line++;
                }
                skip_space = 1;
                if (c_character > 72) {
                    putchar('\n');
                    empty_line = 1;
                    c_space = 0;
                    c_line = 0;
                }
                c_character = 0;
            }
            else {
                putchar(ch);
                c_character++;
            }
        }
    } 
}


int main() {

    *word = '\0';
    c_line = c_space = c_character = c_newline = 0;
    skip_space = break_line = last_space = 0;
    empty_line = 1;
    
    while ((ch = getchar()) != EOF) {
        c_line++;
        
        if (c_line == 73) {
            keeping_word = 0;
        }
        if (c_line > 72)
            housekeep();
        else if (ch == '\n')
            newline();
        else if (ch == ' ') {
            space();
            last_space = 1;
        }
        else
            character();
    }
    if (c_newline > 0)
        putchar('\n');
        
    return 0;
}
