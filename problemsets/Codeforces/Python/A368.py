"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:[*map(int,input().split())]
n,d=I()
a=sorted(I())
r=0
for i in range(I()[0]):r+=i<n and a[i]or-d
print(r)
