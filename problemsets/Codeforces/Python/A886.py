"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=*map(int,input().split()),
s=sum(a)
print('YNEOS'[s%2 or all(a[i]+a[j]+a[k]!=s//2 for i in range(6) for j in range(i+1,6) for k in range(j+1,6))::2])