"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import re
import string
n,k=map(int,input().split())
a=input()
c={}
u=l=0
for x in a:
  if (x!=l):
    c[l]=c.get(l,0)+u//k
    u=0
  u+=1
  l=x
c[l]=c.get(l,0)+u//k
print(max(c.get(x,0) for x in string.ascii_lowercase))