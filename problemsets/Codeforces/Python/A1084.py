"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=i=0
for x in map(int,[*open(0)][1].split()):
  r+=4*i*x
  i+=1
print(r)