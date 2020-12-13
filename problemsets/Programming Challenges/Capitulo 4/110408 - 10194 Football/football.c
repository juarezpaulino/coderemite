/* Football */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char team_name[32];
    int points;
    int games;
    int wins;
    int ties;
    int losses;
    int g_scored;
    int g_against;
} team;

team teams[30];

int search_team(char *team_name, int num) {
    int i;
    
    for (i = 0; i < num; i++)
        if (!strcmp(team_name, teams[i].team_name))
            return (i);
    return -1;
}

int compare_teams(const void *a, const void *b) {

    int i;
    char aux1[35], aux2[35];
    team *x = (team *)a;
    team *y = (team *)b;
    
    if (x -> points != y -> points)
        return (y -> points - x -> points);
    
    if (x -> wins != y -> wins)
        return (y -> wins - x -> wins);
        
    if ((x -> g_scored - x -> g_against) != (y -> g_scored - y -> g_against))
        return ((y -> g_scored - y -> g_against) - (x -> g_scored - x -> g_against));
    
    if (x -> g_scored != y -> g_scored)
        return (y -> g_scored - x -> g_scored);
    
    if (x -> games != y -> games)
        return (x -> games - y -> games);
    
    for (i = 0; x -> team_name[i] != '\0'; i++)
        aux1[i] = toupper(x -> team_name[i]);
    aux1[i] = '\0';
    
    for (i = 0; y -> team_name[i] != '\0'; i++)
        aux2[i] = toupper(y -> team_name[i]);
    aux2[i] = '\0';
    
    return(strcmp(aux1, aux2));
}


int main() {

    int cases;
    int num_teams, t_games;
    char tournament[125], buffer[35], buffer2[35];
    int i, pos, pos2, g1, g2;
    
    scanf("%d", &cases);
    gets(buffer);
    while (cases) {
        scanf("%[^\n]%*c", tournament);
        
        scanf("%d", &num_teams);
        gets(buffer);
        for (i = 0; i < num_teams; i++) {
            scanf("%[^\n#@]", teams[i].team_name);
            gets(buffer);
            teams[i].points = 0;
            teams[i].games = 0;
            teams[i].wins = 0;
            teams[i].ties = 0;
            teams[i].losses = 0;
            teams[i].g_scored = 0;
            teams[i].g_against = 0;
        }
        
        scanf("%d", &t_games);
        gets(buffer);
        for (i = 0; i < t_games; i++) {
            scanf("%[^#]%*c%d%*c%d%*c%[^\n]", buffer, &g1, &g2, buffer2);
            pos = search_team(buffer, num_teams);
            pos2 = search_team(buffer2, num_teams);
            teams[pos].games++;
            teams[pos2].games++;
            teams[pos].g_scored += g1;
            teams[pos2].g_scored += g2;
            teams[pos].g_against += g2;
            teams[pos2].g_against += g1; 
            if (g1 > g2) {
                teams[pos].points += 3;
                teams[pos].wins++;
                teams[pos2].losses++;
            }
            else if (g1 < g2) {
                teams[pos2].points += 3;
                teams[pos2].wins++;
                teams[pos].losses++;
            }
            else {
                teams[pos].points++;
                teams[pos2].points++;
                teams[pos].ties++;
                teams[pos2].ties++;
            }
            getchar();
        }
                
        qsort(teams, num_teams, sizeof(team), compare_teams);
        
        printf("%s\n", tournament);
        for (i = 0; i < num_teams; i++)
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, teams[i].team_name,
            teams[i].points, teams[i].games, teams[i].wins, teams[i].ties, teams[i].losses,
            teams[i].g_scored - teams[i].g_against, teams[i].g_scored, teams[i].g_against);
        
        if (cases > 1)
            putchar('\n');
        cases--;
    }    
    
    return 0;
}
