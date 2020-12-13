/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <string>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Geodesic distance
//
// - Finds distance on a sphere surface from (latA,lonA) to (latB,lonB).
// - Angles need to be converted angle*M_PI/180.
//
double geodesic_distance(double R, double latA, double lonA, double latB, double lonB){
    return R * acos(    cos(latA)*cos(latB)*cos(lonA-lonB) +
                        sin(latA)*sin(latB) );
}

int N, M, Q;
double LA[110], LB[110];
char A[10101], B[10101];
int adj[110][110];

const double radius = 6378.;

int main() {

    int t = 1;
    while (scanf("%d %d %d", &N, &M, &Q) && (N|M|Q)) {
        map<string,int> mapa;
        for (int i = 0; i < N; i++) {
            scanf("%s %lf %lf", A, LA+i, LB+i);
            mapa[A] = i;
            LA[i] *= M_PI/180.;
            LB[i] *= M_PI/180.;
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) adj[i][j] = (i==j) ? 0 : 1<<29;
        while (M--) {
            scanf("%s %s", A, B);
            int u = mapa[A], v = mapa[B];
            double d = geodesic_distance(radius, LA[u], LB[u], LA[v], LB[v]);
            adj[u][v] = min(adj[u][v],(int)(d+.5));
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            double d = adj[i][k]+adj[k][j];
            if (d < adj[i][j]) adj[i][j] = d;
        }
        if (t > 1) putchar('\n');
        printf("Case #%d\n", t++);
        while (Q--) {
            scanf("%s %s", A, B);
            int u = mapa[A], v = mapa[B];
            if (adj[u][v]==1<<29) printf("no route exists\n");
            else printf("%d km\n", adj[u][v]);
        }
    }

    return 0;
}
