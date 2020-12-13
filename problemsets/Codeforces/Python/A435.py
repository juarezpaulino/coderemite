"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,m=I()
a=r=0
for x in I():
  a+=x
  if a>=m:
    r+=1
    a=[x,0][a==m]
r+=a>0
print(r)
    
