"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
c='^>v<'
a,b=map(c.index,input().split())
n=int(input())
print([['ccw','cw'][(a+n)%4==b],'undefined'][abs(a-b)%2==0])