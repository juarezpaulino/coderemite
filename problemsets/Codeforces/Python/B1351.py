"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  a,b=sorted(map(int,input().split()))
  c,d=sorted(map(int,input().split()))
  print('YNEOS'[b!=d or a+c!=b::2])