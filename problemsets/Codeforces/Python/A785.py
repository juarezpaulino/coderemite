"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n = int(input())
s = 0
d = dict(T=4,C=6,O=8,D=12,I=20)
for _ in range(n):
  a = input()
  s += d[a[0]]
print(s)