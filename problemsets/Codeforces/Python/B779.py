"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=input().split()
k=int(k)
c=v=0
for u in n[::-1]:
  if u=='0':v+=1
  else:c+=1
  if v==k:break
print([c,len(n)-1][v<k])