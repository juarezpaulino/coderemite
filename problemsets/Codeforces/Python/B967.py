"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,a,b=I()
x,*s=I()
s=sorted(s)[::-1]
S=x+sum(s)
for i in range(n):
  if i:S-=s[i-1]
  if x*a>=S*b:break
print(i)
