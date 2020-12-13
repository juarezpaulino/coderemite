"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][1:]:
  a,b=sorted(map(int,s.split()))
  print((a+a)**2 if a+a>=b else b*b)