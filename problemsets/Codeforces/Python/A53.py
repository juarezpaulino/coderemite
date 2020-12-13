"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
s=input()
r=''
n=int(input())
while n:
  a=input()
  if a[:len(s)]==s:
    if r=='' or a<r:
      r=a
  n-=1
print(r=='' and s or r)