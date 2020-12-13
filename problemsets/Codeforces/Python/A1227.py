"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in [0]*int(input()):
  n=int(input())
  a=[[*map(int,input().split())]for _ in [0]*n]
  x,y=[min(x[1]for x in a),max(x[0]for x in a)]
  print(max(0,y-x))
