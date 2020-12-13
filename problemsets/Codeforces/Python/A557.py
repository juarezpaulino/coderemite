"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a,b=map(int,input().split())
c,d=map(int,input().split())
e,f=map(int,input().split())
m=n-a-c-e
x=max(0,min(m,b-a));m-=x
y=max(0,min(m,d-c));m-=y
z=max(0,min(m,f-e));m-=z
print(a+x,c+y,e+z)
