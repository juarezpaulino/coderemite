"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n,k=map(int,input().split())
  if n%2:print([f'YES\n{" ".join(map(str,[1]*(k-1)+[n-k+1]))}','NO'][k%2==0 or k>n])
  else:
    if k%2:print([f'YES\n{" ".join(map(str,[2]*(k-1)+[n-2*(k-1)]))}','NO'][2*k>n])
    else:print([f'YES\n{" ".join(map(str,[1]*(k-1)+[n-k+1]))}','NO'][k>n])