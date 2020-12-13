"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][1:]:
  n,m=map(int,s.split())
  print(0-(-n*m)//2)