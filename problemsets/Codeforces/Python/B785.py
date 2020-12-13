"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=sorted([[*map(int,input().split())]for _ in[0]*n])
m=int(input())
b=sorted([[*map(int,input().split())]for _ in[0]*m])
c=sorted(a,key=lambda x:x[1])
d=sorted(b,key=lambda x:x[1])
print(max(max(0,a[n-1][0]-d[0][1]),max(0,b[m-1][0]-c[0][1])))