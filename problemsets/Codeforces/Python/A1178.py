"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=*map(int,[*open(0)][1].split()),
b=sum(a)
c=a[0];d=[1]
for i,x in enumerate(a[1:],start=2):
  if x <= a[0]//2:
    c+=x;d+=[i]
print([0,f'{len(d)}\n{" ".join(map(str,d))}'][c*2>b])