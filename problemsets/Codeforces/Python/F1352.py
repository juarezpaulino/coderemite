"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  a,b,c=map(int,input().split())
  if b<1:r='0'*(a+1)*(a>0)+'1'*(c+1)*(c>0)
  else:r=('1'*c)+'1'+('0'*a)+'0'+('10'*b)[:b-1]*(b>1)
  print(r)

