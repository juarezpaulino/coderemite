"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
a=input()
x=0
if k>n//2:x=1;k=n-k;a=a[::-1]
else:k-=1
if k:print(*[['LEFT','RIGHT'][x]]*k,sep='\n')
print(f'PRINT {a[0]}')
for i in range(1,n):
  print(['LEFT','RIGHT'][1-x])
  print(f'PRINT {a[i]}')
