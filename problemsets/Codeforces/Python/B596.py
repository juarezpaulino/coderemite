"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=c=0
for x in map(int,[*open(0)][1].split()):
  r+=abs(x-c)
  c=x
print(r)