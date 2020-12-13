"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=[0]*(n+1)
for i,x in enumerate(map(int,input().split())):
  a[x]=i
x=y=0
input()
for u in map(int,input().split()):
  x+=a[u]+1
  y+=n-a[u]
print(x,y)
