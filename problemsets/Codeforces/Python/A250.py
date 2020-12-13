"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=c=0;r=[]
for x in map(int,[*open(0)][1].split()):
  if x<0:
    if n==2:
      r+=[c]
      n=1
      c=0
    else:n+=1
  c+=1
r+=[c]
print(len(r))
print(*r)