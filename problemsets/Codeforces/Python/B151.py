"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
r=[]
y=[0,0,0]
for _ in [0]*n:
  m,s=input().split()
  m=int(m)
  x=[s,0,0,0]
  while m:
    t=''.join(input().split('-'))
    if len({*t})<2: x[1]+=1
    elif len({*t})==6 and sorted(t)[::-1]==[*t]: x[2]+=1
    else: x[3]+=1
    m-=1
  r.append(x)
  y=[max(u,v) for u,v in zip(y,x[1:])]
print("If you want to call a taxi, you should call: ",end='')
print(*[u[0]for u in r if u[1]==y[0]],sep=', ',end='.\n')
print("If you want to order a pizza, you should call: ",end='')
print(*[u[0]for u in r if u[2]==y[1]],sep=', ',end='.\n')
print("If you want to go to a cafe with a wonderful girl, you should call: ",end='')
print(*[u[0]for u in r if u[3]==y[2]],sep=', ',end='.\n')