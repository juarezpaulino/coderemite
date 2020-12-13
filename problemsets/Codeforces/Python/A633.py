"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a,b,c=map(int,input().split())
r=0
for i in range(100):
  if i*a>c:break
  if (c-(a*i))%b<1:r=1
print('YNeos'[1-r::2])