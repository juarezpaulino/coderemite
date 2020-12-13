"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
x=a[0]
r=j=0
for c in a:
  if c!=x or j==5:
    x=c;j=0;r+=1
  j+=1
print(r+1)
  