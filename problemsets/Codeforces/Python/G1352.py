"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in[*open(0)][1:]:
  n=int(s)
  if n<4:
    print(-1)
  else:
    b=[*range(n-1,0,-2)]
    b[0],b[1]=b[1],b[0]
    print(*[*range(2-n%2,n+1,2),*b])
    