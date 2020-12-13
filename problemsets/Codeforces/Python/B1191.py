"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=sorted(input().split())
r=len({*a})-1
a=sorted(a,key=lambda x:(x[1],x[0]))
v,s=[*zip(*a)]
c=1
for i in range(1,3):
  if s[i]==s[i-1] and int(v[i-1])+1==int(v[i]):
    c+=1
    r=min(r,3-c)
  elif s[i]==s[i-1] and int(v[i-1])+2==int(v[i]):
    r=min(r,1)
  else:c=1
print(r)
