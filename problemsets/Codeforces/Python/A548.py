"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
n=len(a)
k=int(input())
l=n//k
m=[a[i*l:i*l+l]for i in range(k)]
print('YNEOS'[n%k>0 or any(x!=x[::-1]for x in m)::2])