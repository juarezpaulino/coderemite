"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
for _ in [0]*n:
  print(*map(lambda x: x if len(x)<11 else x[0]+str(len(x)-2)+x[-1], [input()]))