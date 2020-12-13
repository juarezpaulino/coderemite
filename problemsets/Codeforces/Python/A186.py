"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
b=input()
c=0
r=[]
for x,y in zip(a,b):
  if x!=y:
    c+=1
    r+=[(x,y)]
print('YNEOS'[len(a)!=len(b) or c!=2 or r[0]!=r[1][::-1]::2])