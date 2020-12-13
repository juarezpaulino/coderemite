"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n,m=map(int,input().split())
  a=map(int,input().split())
  if m<n or n<3:print(-1)
  else:
    print(2*sum(a))
    for i in range(n):
      print(i+1,(i+1)%n+1)