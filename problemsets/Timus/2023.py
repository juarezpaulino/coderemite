"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a='AOPR'
b='BMS'
c='DGJKWT'
n=int(input())
r=x=0
while n:
  u=input()[0]
  if u in a:v=0 
  if u in b:v=1 
  if u in c:v=2 
  r+=abs(x-v)
  n-=1
  x = v
print(r)
