"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=[*map(int,input().split())]
r=a[1]-a[0]
print(a[-1]+r*all(y-x==r for x,y in zip(a,a[1:])))
