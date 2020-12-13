"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()+'#'
l,b,c=-1,'',[]
for i,x in enumerate(zip(a,a[1:])):
  if x[0]!=x[1]:
    b+=x[0]
    c+=[i-l]
    l=i
y=len(b)
print([c[y//2]+1,0][y%2==0 or c[y//2]<2 or b!=b[::-1] or any(c[y//2-i]+c[y//2+i]<3 for i in range(1,y//2+1))])