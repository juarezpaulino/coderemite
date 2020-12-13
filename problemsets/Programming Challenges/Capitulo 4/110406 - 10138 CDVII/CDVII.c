/* CDVII */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    char reg[21];
    int time;
    int hr;
    char dir;
    int km;
} id;

typedef struct {
    char reg[21];
    double pay;
} bill;    
    
int taxes[24];
id rec[1000];
bill b[1000];
int n_rec, n_car;
bool valid[1000];

int time_compare(id *x, id *y) {

    return ((*x).time - (*y).time);    
}

int reg_compare(char *x, char *y) {
    
    return (strcmp(x, y));
}

int find_id(int begin) {

    int i;
    
    for (i = begin+1; i < n_rec; i++)
        if (strcmp(rec[begin].reg, rec[i].reg) == 0)
            return (i);
    return (-1);
}

int find_bill(int n) {
    
    int i;
    
    for (i = 0; i < n_car; i++)
        if (strcmp(rec[n].reg, b[i].reg) == 0)
            return (i);
    return (-1);
}


int main() {
    
    int cases;
    int i;
    int month, day, hr, min;
    char dir[10];
    char line[100];
    int pos, p;
    int time_compare();
    int reg_compare();
    
    scanf("%d", &cases);
    while (cases) {
        
        for (i = 0; i < 24; i++)
            scanf("%d", &taxes[i]);
        getchar();
        
        n_rec = 0;
        while (gets(line)) {
            if (*line == '\0')
                break;
            sscanf(line, "%s %d:%d:%d:%d %s %d", rec[n_rec].reg, &month, &day, 
            &rec[n_rec].hr, &min, dir, &rec[n_rec].km);
            rec[n_rec].time = (month*31*24*60)+(day*24*60)+(rec[n_rec].hr*60)+min;
            rec[n_rec].dir = dir[1];
            n_rec++;
        }
        for (i = 0; i < n_rec; i++)
            valid[i] = 1;
        qsort(rec, n_rec, sizeof(id), time_compare);
        
        n_car = 0;
        for (i = 0; i < n_rec; i++) {
            if (valid[i]) {
                valid[i] = 0;
                pos = find_id(i);
                if (pos != -1)
                    if ((rec[i].dir == 'n') && (rec[pos].dir == 'x')) {
                        valid[pos] = 0;
                        p = find_bill(i);
                        if (p == -1) {
                            strcpy(b[n_car].reg, rec[i].reg);
                            b[n_car].pay = 2.0;
                            p = n_car;
                            n_car++;
                        }
                        b[p].pay += 1.0;
                        b[p].pay += fabs(rec[i].km - rec[pos].km)*(taxes[rec[i].hr]/100.0);
                    }
            }
        }
        
        qsort(b, n_car, sizeof(bill), reg_compare);
        
        for (i = 0; i < n_car; i++)
            printf("%s $%.2lf\n", b[i].reg, b[i].pay);
        
        cases--;
        if (cases)
            putchar('\n');
    }
    
    return 0;
}
