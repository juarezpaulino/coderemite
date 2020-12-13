"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
for _ in[0]*n:
  if '+' in input():n+=1
n+=2
if n==13:n+=1
print(n*100)