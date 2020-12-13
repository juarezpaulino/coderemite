"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
m=r=-1
for i,x in enumerate(map(int,[*open(0)][1].split())):
  if x>m+1:
    r=i+1
    break
  m=max(m,x)
print(r)