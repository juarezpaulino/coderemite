"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
p=[*map(int,input().split())]
for k in range(n):
  print(p.index(k+1)+1,end=' ')