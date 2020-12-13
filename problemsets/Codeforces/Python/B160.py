"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=*map(int,input()),
a,b=sorted(a[:n]),sorted(a[n:])
d=[1,-1][a[0]>b[0]]
print('NYOE S'[all(d*x<d*y for x,y in zip(a,b))::2])