"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in[*open(0)][1:]:
  n,a,b,c,d=map(int,s.split())
  a,b=sorted([(n*(a-b),n*(a+b)),(c-d,c+d)])
  print('YNeos'[a[1]<b[0]::2])