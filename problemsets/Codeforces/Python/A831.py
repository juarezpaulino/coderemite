"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=*map(int,input().split()),
l=0
r=n
while l+1<n and a[l]<a[l+1]: l+=1
while r>0 and a[r-2]>a[r-1]: r-=1
print('YNEOS'[len({*a[l:r]})!=1::2])
    