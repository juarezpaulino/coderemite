"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
s=set()
for x in a:
  if ord(x)>64:s|={x}
r=10**a.count('?')
for i in range(len(s)):r*=10-i
if ord(a[0])>57:r=r//10*9
print(r)