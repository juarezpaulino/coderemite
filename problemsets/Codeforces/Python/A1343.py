"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n=int(input())
  k=[x for x in range(1,31) if n%((2<<x)-1)<1][0]
  print(n//((2<<k)-1))