"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=*map(int,input().split()),
c=[[0,1][x+y==z]for x,y,z in zip(a,a[1:],a[2:])]+[0]
for i in range(1,n-2):c[i]=c[i]*(c[i]+c[i-1])
print(max(c)+2-(n<2))