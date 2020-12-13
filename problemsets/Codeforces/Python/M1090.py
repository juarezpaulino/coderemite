"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
l=c=r=0
for x in map(int,[*open(0)][1].split()):
  if x==l:c=0
  l=x
  c+=1
  r=max(r,c)
print(r)