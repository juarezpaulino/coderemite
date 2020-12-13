"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import math
import string
from bisect import bisect_left

def solve():
  input()
  a=[*map(int,input().split())]
  c=0
  for x,y in zip(a,a[1:]):
    c=1-c
    if x!=y:
      b = math.gcd(x,y) if c==0 else a[0]//math.gcd(x,y)
      break
  v=[b]
  for x in a:
    b=x//b
    v+=[b]
  p=sorted(set(v))
  ret=""
  for x in v:ret+=string.ascii_uppercase[p.index(x)]
  print(ret)

for t in range(int(input())):
  print("Case #{}: ".format(t+1),end="")
  solve()
