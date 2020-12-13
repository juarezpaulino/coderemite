"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,a=int(input()),['',[],[]]
for _ in [0]*n:
  x,y,_=map(int,input().split())
  a[x].append(y)
print(*(['LIVE','DEAD'][sum(a[x])<5*len(a[x])] for x in [1,2]),sep='\n')