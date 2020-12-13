/* Erdös Number */

#include <stdio.h>
#include <string.h>

#define MAXPERLINE 12
#define MAXAUTHORS 101
#define MAXNAME 40
#define INFINITY 1000000000

typedef struct {
    char name[MAXNAME];
    int num;
} id;

struct {
    id authors[MAXAUTHORS];
    int n_erdos;
} erdos;

struct {
    id paper[MAXPERLINE];
    int n_authors;
} data[101];

char data_valid[101];

int search(char *name) {
    
    int i;
    
    for (i = 0; i < erdos.n_erdos; i++)
        if (!strcmp(erdos.authors[i].name, name))
            return (i);
    return -1;
}

void read_data(int p) {

    char line[300], word[MAXNAME], got;
    int i, j, k, pos;
    
    for (i = 0; i < p; i++) {
        if (!gets(line))
            break;   
        
        j = 0;
        data[i].n_authors = 0;
        while (line[j] != ':') {
            k = 0;
            got = 0;
            while (line[j] == ' ')
                j++;
            while ((!got) || (line[j] != ',')) {
                if ((line[j] == ':') || (line[j] == '\0'))
                    break;
                if (line[j] == ',')
                    got = 1;
                word[k] = line[j];
                k++;
                j++;
            }
            if (line[j] == '\0')
                break;
            if (line[j] == ',')
                j++;
            word[k] = '\0';
            if (got) {
                strcpy(data[i].paper[data[i].n_authors].name, word);
                if ((pos = search(word)) == -1) {
                    strcpy(erdos.authors[erdos.n_erdos].name, word);
                    erdos.authors[erdos.n_erdos].num = INFINITY;
                    data[i].paper[data[i].n_authors].num = erdos.n_erdos;
                    erdos.n_erdos++;
                }
                else
                    data[i].paper[data[i].n_authors].num = pos;
                data[i].n_authors++;
            }
        }
    }
}

int find_min(int line) {

    int i;
    int min = INFINITY;
    
    for (i = 0; i < data[line].n_authors; i++)
        if (erdos.authors[data[line].paper[i].num].num < min)
            min = erdos.authors[data[line].paper[i].num].num;
    
    return (min);
}

int main() {
    
    int scenarios, p, n, number, min;
    char changed, name[MAXNAME], word[500];
    int scen, i, j;
    
    strcpy(erdos.authors[0].name, "Erdos, P.");
    erdos.authors[0].num = 0;
    
    scanf("%d", &scenarios);
    for (scen = 1; scen <= scenarios; scen++) {
        scanf("%d %d", &p, &n);
        getchar();
        
        erdos.n_erdos = 1;
        
        read_data(p);
        
        for (i = 0; i < p; i++)
            data_valid[i] = 1;
        
        changed = 1;
        min = 0;
        while (changed) {
            changed = 0;
            for (i = 0; i < p; i++) {
                if (data_valid[i])
                    if (min == find_min(i)) {
                        data_valid[i] = 0;
                        for (j = 0; j < data[i].n_authors; j++)
                            if (erdos.authors[data[i].paper[j].num].num > (min + 1)) {
                                erdos.authors[data[i].paper[j].num].num = min + 1;
                                changed = 1;
                            }
                    }
            }
            min++;
        }
    
        printf("Scenario %d\n", scen);
        for (i = 0; i < n; i++) {
            gets(name);
            j = search(name);
            printf("%s ", name);
            if (j == -1)
                printf("infinity\n");
            else if (erdos.authors[j].num == INFINITY)
                printf("infinity\n");
            else
                printf("%d\n", erdos.authors[j].num);
        }
    }

    return 0;
}
