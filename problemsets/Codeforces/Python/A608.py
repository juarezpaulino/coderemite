"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,s=I()
exec('a=sorted(['+n*'[*I()],'+'])[::-1]')
r=t=0
for x,y in a:
  v=t+s-x
  if v<y:v=y
  r+=v-t
  t=v
  s=x
print(r+s)
