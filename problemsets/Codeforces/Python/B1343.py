"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n=int(input())
  a=[*range(2,n+1,2)]
  b=[*range(1,n,2)]
  b[-1]+=n//2
  print(['YES\n'+' '.join(map(str,a+b)),'NO'][n%4>0])
