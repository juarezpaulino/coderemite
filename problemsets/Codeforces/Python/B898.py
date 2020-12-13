"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,a,b=[int(input())for _ in[0]*3]
for i in range(n+2):
  if i*a>n:break
  if (n-i*a)%b<1:
    print(f'YES\n{i} {(n-i*a)//b}')
    break
if i*a>n:print('NO')