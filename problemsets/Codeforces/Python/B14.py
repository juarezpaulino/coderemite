"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
l=0;r=1E4
n,x=map(int,input().split())
for _ in[0]*n:
  a,b=sorted(map(int,input().split()))
  l=max(l,a)
  r=min(r,b)
print([[[x-r,l-x][x<l],0][l<=x<=r],-1][l>r])