"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=map(int,input().split())
A=[input()for _ in[0]*n]
a=b=1E2;c=d=-1
for y in range(n):
  for x in range(m):
    if A[y][x]=='*':
      a=min(a,y);b=min(b,x)
      c=max(c,y);d=max(d,x)
print(*[x[b:d+1]for x in A[a:c+1]],sep='\n')
