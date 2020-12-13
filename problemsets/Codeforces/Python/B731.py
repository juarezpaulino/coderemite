"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
c=0
for x in map(int,input().split()):
  c=x-c
  if c<0:break
  c%=2
print('YNEOS'[c!=0::2])