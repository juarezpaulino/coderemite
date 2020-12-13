"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[*open(0)][1]
s={}
r=0
for x,y in [*zip(a,a[1:])][::2]:
  s[x.upper()]=s.get(x.upper(),0)+1
  if s.get(y,0)>0:s[y]-=1
  else:r+=1
print(r)