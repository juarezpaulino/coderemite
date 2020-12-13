"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=0
for _ in [0]*int(input()):
  r+=sum(map(int,input().split()))>1
print(r)