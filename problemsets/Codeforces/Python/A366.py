"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
for i in range(4):
  a,b,c,d=map(int,input().split())
  a=min(a,b)
  c=min(c,d)
  if a+c<=n:
    print(i+1,a,n-a)
    break
else: print(-1)
