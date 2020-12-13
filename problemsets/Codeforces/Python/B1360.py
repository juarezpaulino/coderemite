"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][2::2]:
  a=sorted(map(int,s.split()))
  print(min(y-x for x,y in zip(a,a[1:])))