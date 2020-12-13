"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,t,k,d=map(int,input().split())
u=0--n//k
u-=d//t+1
print('YNEOS'[u<=0::2])