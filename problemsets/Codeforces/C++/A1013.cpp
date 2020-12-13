/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<iostream>
using namespace std;
int n,a,k,i,x;
int main(){cin>>n;for(k=1;k>-2;k-=2)for(i=0;i<n;i++)cin>>x,a+=k*x;puts(a<0?"No":"Yes");}