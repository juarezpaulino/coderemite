/* Rouba Monte */

int n, j;
int desc[14];
int nc[21];
int topo[21];


int main() {
    
    int i, k;
    int vez;
    int p;
    char flag;
    
    while (scanf("%d %d", &n, &j)) {
        
        if ((!n) && (!j)) break;   
        
        for (i = 1; i <= j; i++) nc[i] = 0;
        for (i = 1; i <= 13; i++) desc[i] = 0;
        
        p = 1;
        for (i = 0; i < n; i++) {
            scanf("%d", &vez);
            
            if (desc[vez]) {
                nc[p] += desc[vez]+1; 
                desc[vez] = 0; 
                topo[p] = vez;
                continue;
            }
            
            flag = 0;
            for (k = 1; k <= j; k++)
                if ((k != p) && (nc[k]) && (vez == topo[k])) {
                    flag = 1;
                    nc[p] += nc[k];
                    nc[k] = 0;
                }
            if (flag) { nc[p]++; topo[p] = vez; continue; }
            
            if ((nc[p]) && (topo[p] == vez)) { nc[p]++; continue; }
            
            desc[vez]++;
            p = p+1;
            if (p > j) p = 1;
        }
        
        p = -1;
        for (i = 1; i <= j; i++) if (nc[i] > p) p = nc[i];
        printf("%d", p);
        for (i = 1; i <= j; i++)
            if (nc[i] == p)
                printf(" %d", i);
        putchar('\n');
    }
    
    return 0;
}
