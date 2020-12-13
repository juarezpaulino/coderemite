"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n,m=map(int,input().split())
  print([[m,2*m][n>2],0][n<2])