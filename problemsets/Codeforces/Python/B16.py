"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,m=I()
r=0
for x in sorted([[*I()]for _ in[0]*m],key=lambda x:x[1])[::-1]:
  v=min(n,x[0])
  r+=v*x[1]
  n-=v
  if n<1:break
print(r)
