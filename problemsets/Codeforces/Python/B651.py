"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
d={}
for x in [*open(0)][1].split():
  d[x] = d.get(x,0)+1
ret=0
while 1:
  k=len(d.keys())
  if k<1:break
  x=min(d.values())
  for v in [*d.keys()]:
    if d[v]==x:d.pop(v)
    else:d[v]-=x
  ret += (k-1)*x
print(ret)