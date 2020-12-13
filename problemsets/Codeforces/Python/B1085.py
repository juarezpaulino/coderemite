"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
r=int(1E9)
for i in range(1,k):
  if n%i<1:r=min(r,n*k//i+i)
print(r)