"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a,b=map(int,input().split())
v=abs(a)+abs(b)
p=[0,v*(-1)**(b<0)]
q=[v*(-1)**(a<0),0]
if a<0:p,q=q,p
print(*p,*q)