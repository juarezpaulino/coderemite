/* Crypt kicker */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char dictionary[9][16][1000][17];
short int ranges[9][16];
char l_words[80][17];
int n_words;
char finished;

int compare(const void *a, const void *b) {

    char *x, *y;
    int rep1, rep2, len1, len2;
    
    x = (char *) a;
    y = (char *) b;
    
    rep1 = count_repeated(x, &len1);
    rep2 = count_repeated(y, &len2);
    
    if (rep1 != rep2)
        return (rep2 - rep1);
    if (len1 != len2)
        return (len2 - len1);
    return 0;
}

int search(char solution[], char ch) {
    
    int i;
    
    for (i = 0; i < 27; i++)
        if (ch == solution[i])
            return i;
    return -1;
}

int count_repeated(char *word, int *len) {

    int count, i, j;
    char aux[17];
    
    *aux = '\0';
    count = 0;
    for (i = 0; word[i] != '\0'; i++) {
        for (j = 0; aux[j] != '\0'; j++)
            if (aux[j] == word[i]) {
                count++;
                break;
            }
        if (aux[j] == '\0') {
            aux[j] = word[i];
            aux[j+1] = '\0';
        }
    }
    *len = i - 1;
    
    return (count);
}

void construct_candidates(char c[][17], int *ncandidates, int k) {
    
    int i, len, rep;
    
    *ncandidates = 0;
    rep = count_repeated(l_words[k], &len);
    
    for (i = 0; i < ranges[rep][len]; i++) {
        strcpy(c[*ncandidates], dictionary[rep][len][i]);
        (*ncandidates)++;
    }
}

void backtrack(char solution[], int k) {

    char c[1000][17];
    int ncandidates, i, j, l;
    char aux_solution[26];

    if (k == (n_words - 1))
        finished = 1;
    else {
        k++;
        construct_candidates(c, &ncandidates, k);
        for (i = 0; i < ncandidates; i++) {
            memcpy(aux_solution, solution, 26);
            for (j = 0; l_words[k][j] != '\0'; j++)
                if (aux_solution[c[i][j] - 'a'] != '\0') {
                    if (aux_solution[c[i][j] - 'a'] != l_words[k][j])
                        break;
                }
                else {
                    for (l = 0; l < 26; l++)
                        if (aux_solution[l] == l_words[k][j])
                            break;
                    if (l != 26)
                        break;
                    aux_solution[c[i][j] - 'a'] = l_words[k][j];
                }
            if (l_words[k][j] != '\0')
                continue;
            backtrack(aux_solution, k);
            if (finished) {
                memcpy(solution, aux_solution, 26);
                return;
            }
        }
    }
}

int main() {

    int n, i, len, rep, j;
    char word[17], line[81];
    char solution[26];
    
    memset(ranges, 0, sizeof(short int)*9*16);
    scanf("%d", &n);
    getchar();
    
    for (i = 0; i < n; i++) {
        gets(word);
        rep = count_repeated(word, &len);
        if (strcmp(word, dictionary[rep][len][ranges[rep][len] - 1])) {
            strcpy(dictionary[rep][len][ranges[rep][len]], word);
            ranges[rep][len]++;
        }
    }
    
    while (gets(line)) {
        i = 0;
        n_words = 0;
        while (line[i] != '\0') {
            while (line[i] == ' ')
                i++;
            if (line[i] == '\0')
                break;
            j = 0;
            while ((line[i] != ' ') && (line[i] != '\0')) {
                word[j] = line[i];
                j++;
                i++;
            }
            word[j] = '\0';
            strcpy(l_words[n_words], word);
            n_words++;
        }

        qsort(l_words, n_words, sizeof(char)*17, compare);

        memset(solution, '\0', 26);        
        finished = 0;
        backtrack(solution, -1);
        
        if (!finished)
            for (i = 0; line[i] != '\0'; i++)
                if (line[i] == ' ')
                    putchar(' ');
                else
                    putchar('*');
        else
            for (i = 0; line[i] != '\0'; i++)   
                if (line[i] == ' ')
                    putchar(' ');
                else {
                    j = search(solution, line[i]);
                    putchar('a' + j);
                }
        putchar('\n');   
    }
    return 0;
}
