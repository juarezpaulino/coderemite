"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
h,m=map(int,input().split(':'))
m+=h*60
while 1:
  m=(m+1)%1440  
  r=f'{m//60:02}:{m%60:02}'
  if r==r[::-1]:
    print(r)
    break
