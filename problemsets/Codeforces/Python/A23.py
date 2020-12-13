"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
n=len(a)
for l in range(n,0,-1):
  for i in range(n-l+1):
    if a[i:i+l] in a[i+1:]:
      print(l)
      exit(0)
print(0)