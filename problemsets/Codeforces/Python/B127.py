"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
d={}
for x in map(int,[*open(0)][1].split()):
  d[x]=d.get(x,0)+1
r=0
for x in d.values():r+=x//2
print(r//2)