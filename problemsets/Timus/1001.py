"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[]
for s in [*open(0)]:
  for x in map(int,s.split()):
    a+=[x]
for x in a[::-1]:
  print(x**.5)