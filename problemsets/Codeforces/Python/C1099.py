"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
n=len(a)
k=int(input())
m=k-sum(all(c.isalpha() for c in x) for x in zip(a,a[1:]+'a'))
r=''
if m>=0:
  for i in range(n):
    if i<n-1 and not a[i+1].isalpha():
      if m:
        if a[i+1]=='?':r+=a[i];m-=1
        else:r+=a[i]*m;m=0
    elif a[i].isalpha():r+=a[i]
print('Impossible' if m else r)
