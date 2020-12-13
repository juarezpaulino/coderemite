"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
r=0
while n:
  a=input()
  r+=all(a.count(str(i))for i in range(k+1))
  n-=1
print(r)