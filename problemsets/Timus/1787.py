"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
k,n=map(int,input().split())
r=0
for x in map(int,input().split()):
  r=max(0,r+x-k)
print(r)