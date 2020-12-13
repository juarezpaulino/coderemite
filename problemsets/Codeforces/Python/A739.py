"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,k=I()
a=*I(),
x=min(a)
print([sum((y-x)//k for y in a),-1][any(y%k!=x%k for y in a)])