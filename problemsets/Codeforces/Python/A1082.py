"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][1:]:
  n,x,y,d=map(int,s.split())
  a,b,c=abs(x-y)//d,(x+d-1)//d+(y-1)//d,-((x-n)//d)+(n-y)//d
  r=a if x%d==y%d else -1
  if r<0 and y%d==1:r=b
  if n%d==y%d:r=[min(r,c),c][r<0]
  print(r)