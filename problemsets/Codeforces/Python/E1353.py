"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
INF=int(1E8)
for _ in[0]*int(input()):
  n,k=map(int,input().split())
  a=[0]+[*map(int,input())]
  b=[0]*(n+1)
  for i in range(1,n+1):b[i]+=b[i-1]+a[i]
  r=[INF]*(n+1)
  r[0]=0
  for i in range(1,n+1):
    r[i]=min(r[i],b[i-1]+(a[i]<1))
    if i>k:r[i]=min(r[i],r[i-k]+b[i-1]-b[i-k]+(a[i]<1))
  c=b[n]
  for i in range(1,n+1):c=min(c,r[i]+b[n]-b[i])
  print(c)


