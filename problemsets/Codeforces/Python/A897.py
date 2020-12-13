"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
_,m=map(int,input().split())
a=input()
for _ in [0]*m:
  l,r,b,c=input().split();l=int(l)-1;r=int(r)
  a=a[:l]+a[l:r].replace(b,c)+a[r:]
print(a)