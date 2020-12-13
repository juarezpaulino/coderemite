"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n=int(input())
  a=*map(int,input().split()),
  i=l=0;j=n-1
  x=y=z=0
  while i<=j:
    c=0
    while i<=j and c<=l:c+=a[i];i+=1
    z+=1;x+=c;l=c
    if i>j:break

    c=0
    while i<=j and c<=l:c+=a[j];j-=1
    z+=1;y+=c;l=c
  print(z,x,y)

