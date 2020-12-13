"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n,k=map(int,input().split())
  x=k%(n-1)
  print(k//(n-1)*n+x-(x<1))