"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=0
for x in map(int,[*open(0)][1].split()):
  r=max(r,min(x-1,1000000-x))
print(r)