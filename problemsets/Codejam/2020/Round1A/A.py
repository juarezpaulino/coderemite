"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
from fnmatch import fnmatch
def solve():
  n=int(input())
  v=[input()for _ in[0]*n]
  a='*'
  for i in range(n):a=a.replace('*',v[i],1)
  a=a.replace('*','')
  print(a)
  r=1
  for i in range(n):r&=fnmatch(a,v[i])
  print(['*',a][r])
  

for t in range(int(input())):
  print(f'Case #{t+1}: ',end='')
  solve()