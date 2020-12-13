"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
l=[];r=[]
for s in[*open(0)][1:]:
  x,v=map(int,s.split())
  if x<0:l+=[(-x,v)]
  else:r+=[(x,v)]
l=sorted(l)
r=sorted(r)
m=min(map(len,[l,r]))
print(sum(x[1]for x in l[:m+1])+sum(x[1]for x in r[:m+1]))