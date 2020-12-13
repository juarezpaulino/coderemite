"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
rank=[-1]*9999
def f(x):
  if rank[x]<0:rank[x]=x
  if x!=rank[x]:rank[x]=f(rank[x])
  return rank[x]
for _ in[0]*n:
  a,b=map(int,input().split())
  b+=1000
  n-=(rank[a]>=0)+(rank[b]>=0)-(f(a)==f(b))
  rank[f(a)]=f(b)
print(n-1)