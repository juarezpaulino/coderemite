"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
d=2
r=1
while d*d<=n:
  while n%d<1:r+=n;n//=d
  d+=1
if n>1:r+=n
print(r)