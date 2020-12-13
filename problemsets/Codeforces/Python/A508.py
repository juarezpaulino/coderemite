"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m,k=map(int,input().split())
s=set()
dy=[-1,-1,0,0]
dx=[-1,0,-1,0]
for i in range(k):
  y,x=map(int,input().split())
  s|={(y,x)}
  for k in range(4):
    c=0
    for u in range(2):
      for v in range(2):
        a=y+dy[k]+u
        b=x+dx[k]+v
        if (a,b) in s:c+=1
    if c==4:
      print(i+1)
      exit(0)
  k-=1
print(0)