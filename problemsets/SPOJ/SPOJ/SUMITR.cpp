/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <algorithm>
#define S scanf("%d",&
#define F(i,N) for(i=1;i<=N;i++)
int T[150][150],C,N,v,u,i,j;main(){S C);while(C--){S N);F(i,N){u=0;F(j,N)T[i][j]=0;F(j,i)S v),u=std::max(u,T[i][j]=std::max(T[i-1][j],T[i-1][j-1])+v);}printf("%d\n",u);}}
