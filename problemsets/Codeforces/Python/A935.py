"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n = int(input())
r = 0
for x in range(1,n//2+1):
  r += n%x==0
print(r) 