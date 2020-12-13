"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][2::2]:
  a=sorted(map(int,s.split()))
  print(max([1]+[i+2 for i,x in enumerate(a)if x<i+2]))

