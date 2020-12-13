"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
for i in range(n):
  y=(1<<i+1)-1<<i
  if y>n:break
  if n%y<1:x=y
print(x)