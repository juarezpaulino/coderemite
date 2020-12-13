"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=[*map(int,input().split())]
x=sum(a[i]==i for i in range(n))
x+=(x<n)
x+=any(i!=a[i] and i==a[a[i]] for i in range(n))
print(x)