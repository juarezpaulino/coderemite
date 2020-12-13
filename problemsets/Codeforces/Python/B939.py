"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,k=I()
a=*I(),
r=min(range(k),key=lambda x:n%a[x])
print(r+1,n//a[r])