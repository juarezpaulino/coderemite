"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
x=y=r=0
dx=[-1,0,1,0]
dy=[0,1,0,-1]
d='LURD'
v={(0,0):1}
for c in [*open(0)][1][:-1]:
  c=d.index(c)
  x+=dx[c]
  y+=dy[c]
  if (x,y) in v:r+=v[(x,y)];v[(x,y)]+=1
  else:v[(x,y)]=1
print(r)