/* Lazy Jumping Frog */

#include <stdio.h>
#include <stdlib.h>

#define MAXINT 1000000000
#define MAXG 1001
#define nBuckets 5

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    short int X;
    short int Y;
} ITEM;

int c;
int r;
bool watery[MAXG][MAXG];
int distance[MAXG][MAXG];
bool valid[MAXG][MAXG];
int cf, rf, ct, rt;

/* Implementation of Radix-Heap */
typedef struct RadixHeapNode{
    ITEM item;
    int key;
    char bucket;
    struct RadixHeapNode *next, *prev;
} RadixHeapNode;

RadixHeapNode *nodes[MAXG][MAXG];
RadixHeapNode *bucketHeaders;
int *u;
int dMin;
int itemCount;

void RadixHeap();
void DeleteRadixHeap();    
ITEM deleteMin();
void insert(ITEM item, long k);
void decreaseKey(ITEM item, long newValue);
void placeNode(int startBucket, RadixHeapNode *node);
void insertNode(int i, RadixHeapNode *node);
void removeNode(RadixHeapNode *node);

void RadixHeap() {
    
    RadixHeapNode blankNode;
    int i, j;
    int l;
    
    itemCount = 0;
    dMin = 0;

    /* allocate node lookup array (indexed by item no) */
    for (j = 0; j <= c; j++)
        for (i = 0; i <= r; i++)
            nodes[j][i] = 0;

    /* allocate and initialise buckets */
    blankNode.next = blankNode.prev = 0;
    blankNode.item.X = blankNode.item.Y = -1;
    blankNode.bucket = -1;
    blankNode.key = -1;    
    bucketHeaders = (RadixHeapNode *) malloc(sizeof(RadixHeapNode)*(nBuckets+1));
    for(i = 0; i <= nBuckets; i++) {
        bucketHeaders[i] = blankNode;
        bucketHeaders[i].next = &bucketHeaders[i];
        bucketHeaders[i].prev = &bucketHeaders[i];
    }

    /* allocate and initialise upper-limits of buckets */
    u = (int *) malloc(sizeof(int)*(nBuckets+1));
    u[0] = -1;
    l = 1;
    for(i = 1; i <= nBuckets; i++) {
        u[i] = l - 1;
        l *= 2;
    }
    u[nBuckets] = (c*r)*7 + 1;
}

void DeleteRadixHeap() {
    
    int i, j;
    
    for (j = 0; j <= c; j++)
        for (i = 0; i <= r; i++)
            if (nodes[j][i] != 0)
                free(nodes[j][i]);
    free(bucketHeaders);
    free(u);
}

void insert(ITEM item, long k) {
    
    RadixHeapNode *newNode =  (RadixHeapNode *) malloc(sizeof(RadixHeapNode));
    
    newNode->item.X = item.X;
    newNode->item.Y = item.Y;
    newNode->key = k;
    nodes[item.X][item.Y] = newNode;
    placeNode(nBuckets,newNode);
    itemCount++;
}

void decreaseKey(ITEM item, long k) {
    
    RadixHeapNode *node;
    
    node = nodes[item.X][item.Y];
    removeNode(node);
    node->key = k;
    placeNode(node->bucket, node);
}

ITEM deleteMin() {
    
    RadixHeapNode *minNode;
    ITEM minItem;
    int i, j;
    RadixHeapNode *header;
    int minKey;
    RadixHeapNode *node;
    int l, s, uMax;
    RadixHeapNode *nextNode;
    
    /* if bucket 1 is nonempty, return any of its nodes as the minimum */
    if(bucketHeaders[1].next != &bucketHeaders[1]) {
        minNode = bucketHeaders[1].next;
        removeNode(minNode);
        minItem = minNode->item;
        nodes[minItem.X][minItem.Y] = 0;
        free(minNode);
        itemCount--;
        return (minItem);
    }

    /* find i such that bucket i is the smallest nonempty bucket */
    i = 2;
    while(bucketHeaders[i].next == &bucketHeaders[i]) i++;

    /* find and remove the minimum node from bucket i */
    header = &bucketHeaders[i];
    minNode = bucketHeaders[i].next;
    minKey = minNode->key;
    node = minNode->next;
    while(node != header) {
        if(node->key < minKey) {
            minNode = node;
            minKey = node->key;
        }
        node = node->next;
    }
    removeNode(minNode);

    /* recalulate upper bounds on empty buckets */
    u[0] = minKey - 1;
    u[1] = minKey;
    l = 1;
    s = minKey;
    uMax = u[i];
    for(j = 2; j < i; j++) {
        s += l;
        u[j] = s < uMax ? s : uMax;
        l *= 2;
    }

    /* Every vertex in u[i] can now be moved to the empty lower buckets.
     * This is gauranteed since the condition u[i] = u[i-1] must hold.
     */

    /* place nodes from bucket i into lower buckets */
    nextNode = header->next;
    while(nextNode != header) {
        node = nextNode;
        nextNode = nextNode->next;
        placeNode(i-1, node);
    }

    /* bucket i can now be marked as empty */
    bucketHeaders[i].next = bucketHeaders[i].prev = &bucketHeaders[i];

    /* delete the minimum node and return the corresponding item */
    minItem = minNode->item;
    nodes[minItem.X][minItem.Y] = 0;
    free(minNode);
    itemCount--;
    return (minItem);
}

void placeNode(int startBucket, RadixHeapNode *node) {
    
    /* Place the node in the bucket i <= startBucket that corresponds to its
     * key.
     */
    int key = node->key;
    int i = startBucket;
    do {
        i--;
    } while(u[i] >= key);        
    insertNode(i+1, node);
}

void insertNode(int i, RadixHeapNode *node) {
    
    /* link the node into bucket i */
    RadixHeapNode *tailNode = &bucketHeaders[i];
    RadixHeapNode *prevNode = tailNode->prev;
    node->bucket = i;    
    node->next = tailNode;
    tailNode->prev = node;
    node->prev = prevNode;
    prevNode->next = node;
}

void removeNode(RadixHeapNode *node) {
    
    /* unlink the node from its bucket */
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

/**************************** Fim Radix Heap **********************************/

void dijkstra(ITEM s, ITEM d) {

    ITEM aux;
    ITEM v;
    int weight[5] = { 2, 3, 5, 6, 7 };
    int wg[3][3];
    bool sim, w1,w2,w3,w4,w5,w6,w7,w8;
    int register dx;
    int register dy;
    int register c1;
    int register c2;
    int register r1;
    int register r2;
    int register i;
    int register j;

    RadixHeap();
    insert(s, 0);

    while (itemCount > 0) {
        aux = deleteMin();
        valid[aux.X][aux.Y] = FALSE;
        if (aux.X == d.X && aux.Y == d.Y)
            break;
        
        dx = aux.X;
        dy = aux.Y;
        sim = TRUE; w1=w2=w3=w4=w5=w6=w7=w8=FALSE;
        if ( dx+1 <= c ) if (watery[dx+1][dy]) { sim = FALSE; w1 = TRUE; }
        if ( dx-1 >= 1 ) if (watery[dx-1][dy]) { sim = FALSE; w3 = TRUE; }
        if ( dy+1 <= r ) if (watery[dx][dy+1]) { sim = FALSE; w2 = TRUE; }
        if ( dy-1 >= 1 ) if (watery[dx][dy-1]) { sim = FALSE; w4 = TRUE; }
        if ( (dx-1 >= 1) && (dy-1 >= 1) ) if (watery[dx-1][dy-1]) { sim =
        FALSE; w5 = TRUE; }
        if ( (dx+1 <= c) && (dy+1 <= r) ) if (watery[dx+1][dy+1]) { sim =
        FALSE; w6 = TRUE; }
        if ( (dx+1 <= c) && (dy-1 >= 1) ) if (watery[dx+1][dy-1]) { sim =
        FALSE; w7 = TRUE; }
        if ( (dx-1 >= 1) && (dy+1 <= r) ) if (watery[dx-1][dy+1]) { sim =
        FALSE; w8 = TRUE; }
        
        c1 = dx - 2; c2 = dx + 2;
        r1 = dy - 2; r2 = dy + 2;
        if ( sim ){ c1++;c2--;r1++;r2--; } /* otimiza */
        else {
         /**************************/
         /*  restringe ainda mais  */
         /**************************/
         if ( !w8 && !w3 && !w5 ) c1++;
         if ( !w6 && !w1 && !w7 ) c2--;
         if ( !w5 && !w4 && !w7 ) r1++;
         if ( !w8 && !w2 && !w6 ) r2--;
        }
        
        if ( c1 < 1 ) c1 = 1;
        if ( c2 > c ) c2 = c;
        if ( r1 < 1 ) r1 = 1;
        if ( r2 > r ) r2 = r;
        
        wg[0][1] = wg[1][0] = distance[dx][dy] + weight[0];
        wg[1][1] = distance[dx][dy] + weight[1];
        wg[0][2] = wg[2][0] = distance[dx][dy] + weight[2];
        wg[1][2] = wg[2][1] = distance[dx][dy] + weight[3];
        wg[2][2] = distance[dx][dy] + weight[4];
        for ( j = c1; j <= c2; j++ )
            for ( i = r1; i <= r2; i++ )
                if (!watery[j][i]) {
                    if (valid[j][i] == TRUE)
                        if (distance[j][i] > wg[abs(j-dx)][abs(i-dy)]) {
                            distance[j][i] = wg[abs(j-dx)][abs(i-dy)];
                            v.X = j;
                            v.Y = i;
                            if (nodes[j][i] == 0)
                                insert(v, distance[j][i]);
                            else
                                decreaseKey(v, distance[j][i]);
                        }
                }
    }
    DeleteRadixHeap();
}

void heuristica(){

    int i;
    bool flag;
    int dx,dy;
    int sinalx,sinaly;

    dx = abs(ct - cf);
    dy = abs(rt - rf);
    sinalx = 1;
    sinaly = 1;
    if ( cf > ct ) sinalx = -1;
    if ( rf > rt ) sinaly = -1;

    /* diagonal */
    flag = TRUE;
    if ( dx == dy ){
    i = 1;
    while ( i++ < dx ) if ( watery[cf+(i*sinalx)][rf+(i*sinaly)] ) {flag = FALSE; break;}
    if ( flag ) { distance[ct][rt] = dx*3; return; }
    }
    
    /* reta  x */
    flag = TRUE;
    if ( dy == 0 ){
    i = 1;
    while ( i++ < dx ) if ( watery[cf+(i*sinalx)][rf]) { flag = FALSE; break;}
    if ( flag ) { distance[ct][rt] = dx*2; return; }
    }
    
    /* reta  y */
    flag = TRUE;
    if ( dx == 0 ){
    i = 1;
    while ( i++ < dy ) if ( watery[cf][rf+(i*sinaly)] ) {flag = FALSE; break;}
    if ( flag ) { distance[ct][rt] = dy*2; return; }
    }
    
}

int main() {

   ITEM s, d;
   int c1, r1, c2, r2;
   int num;
   int j, i;
   while (scanf("%d %d", &c, &r)) {

       if ((c == 0) && (r == 0))
           break;

       for (j = 1; j <= c; j++)
           for (i = 1; i <= r; i++)
               watery[j][i] = FALSE;

       scanf("%d %d %d %d", &cf, &rf, &ct, &rt);
       scanf("%d", &num);
       while (num) {
           scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
           for (j = c1; j <= c2; j++)
               for (i = r1; i <= r2; i++)
                   watery[j][i] = TRUE;
           num--;
       }

       s.X = cf;
       s.Y = rf;
       d.X = ct;
       d.Y = rt;
       for( j = 1; j <= c; j++ )
            for( i = 1; i <= r; i++ ) {
                distance[j][i] = MAXINT;
                valid[j][i] = TRUE;
            }
        distance[s.X][s.Y] = 0;
        
       /* só se origem diferente do destino */
       if ( (cf != ct) || (rf != rt) ){
            heuristica(); /* checa se sapinho "enxerga" a sapinha */
            if ( distance[ct][rt] == MAXINT )
                dijkstra(s, d);
       }

       if (distance[ct][rt] == MAXINT)
           printf("impossible\n");
       else
           printf("%d\n", distance[ct][rt]);
   }

   return 0;
}
