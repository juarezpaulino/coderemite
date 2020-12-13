/* Contest Scoreboard */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NPROBLEMS 9
#define NCONTESTANTS 101


/* The 0th position of each field of the structure below is: total time and 
total solved respectively. */
typedef struct {
    int time[NPROBLEMS + 1];
    char solved[NPROBLEMS + 1];
} problems;

typedef struct {
    int team;
    problems p;
} contestant;

contestant contestants[NCONTESTANTS];
int num_cont;

int search(int team) {
    
    int i;
    for (i = 0; i < num_cont; i++)
        if (team == contestants[i].team)
            return i;
    
    return -1;
}

int compare(const void *x, const void *y) {
    
    contestant *a = (contestant *) x;
    contestant *b = (contestant *) y;
    
    if (a -> p.solved[0] != b -> p.solved[0])
        return (b -> p.solved[0] - a -> p.solved[0]);
    else if (a -> p.time[0] != b -> p.time[0])
        return (a -> p.time[0] - b -> p.time[0]);
    else
        return (a -> team - b -> team);
}

int main() {

    int cases;
    char line[82];
    int i, j, team, problem, time, pos;
    
    scanf("%d", &cases);
    getchar();
    getchar();
    while (cases) {
        
        num_cont = 0;
        while(fgets(line, 82, stdin)) {
            if (*line == '\n')
                break;
            for (i = strlen(line) - 1; (line[i] == ' ') || (line[i] == '\n'); i--);
            sscanf(line, "%d %d %d", &team, &problem, &time);
            if ((pos = search(team)) == -1) {
                contestants[num_cont].team = team;
                for (j = 0; j < 10; j++) {
                    contestants[num_cont].p.time[j] = 0;
                    contestants[num_cont].p.solved[j] = 0;
                }
                pos = num_cont;
                num_cont++;
            }
            if ((line[i] == 'R') || (line[i] == 'U') || (line[i] == 'E'))
                continue;
            if (!(contestants[pos].p.solved[problem])) {
                if (line[i] == 'I') 
                    contestants[pos].p.time[problem] += 20;
                else {
                    contestants[pos].p.solved[problem] = 1;
                    contestants[pos].p.time[problem] += time;
                    contestants[pos].p.solved[0]++;
                    contestants[pos].p.time[0] += contestants[pos].p.time[problem];
                }
            }
        }
        
        qsort(contestants, num_cont, sizeof(contestant), compare);
        
        for (i = 0; i < num_cont; i++)
            printf("%d %d %d\n", contestants[i].team, contestants[i].p.solved[0], 
            contestants[i].p.time[0]);
        
        if (cases > 1)
            putchar('\n');
        cases--;
    }
    
    return 0;
}
