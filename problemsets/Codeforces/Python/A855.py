"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,s=int(input()),{''}
for _ in [0]*n:
  a = input()
  print(['NO','YES'][a in s])
  s.add(a)