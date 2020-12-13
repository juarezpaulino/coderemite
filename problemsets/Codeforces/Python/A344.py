"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r,a=0,'a'
for _ in range(int(input())):
  b=input(); r+=a!=b; a=b
print(r)