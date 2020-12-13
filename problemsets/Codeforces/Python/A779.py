"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
input()
a=[0]*6
for i in[1,-1]:
  for x in map(int,input().split()):a[x]+=i 
s=sum(abs(x)for x in a)
print([s//4,-1][any(x%2 for x in a)])
