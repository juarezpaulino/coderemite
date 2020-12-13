"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=input()
x=y=n-11>>1
b=''
for c in a:
  if c=='8' and y:y-=1
  elif c!='8' and x:x-=1
  else:b+=c
print('YNEOS'[b[0]!='8'::2])
