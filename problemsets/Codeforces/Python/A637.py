"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=m=-1
d={}
for x in map(int,[*open(0)][1].split()):
  d[x]=d.get(x,0)+1
  if d[x]>m:m=d[x];r=x
print(r)