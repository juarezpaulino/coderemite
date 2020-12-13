"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
i=lambda:map(int,input().split())
n,c=i();p=[*i()];t=[*i()];s,a,b=0,0,0
for k in range(n):
  a+=t[k]; b+=t[n-1-k]
  s+=max(0,p[k]-a*c)-max(0,p[n-k-1]-b*c)
print([['Tie','Radewoosh'][s<0],'Limak'][s>0])