"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[0,0,*map(int,[*open(0)][1].split())]
x=len(a)-1
r=[x]
while x!=1:
  x=a[x]
  r+=[x]
print(*r[::-1])