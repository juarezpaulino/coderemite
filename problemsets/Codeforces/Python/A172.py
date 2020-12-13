"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[*open(0)][1:]
r=20
for x,y in zip(a,a[1:]):
  for i in range(len(x)):
    if x[i]!=y[i]:break
  r=min(r,i)
print(r)