"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
i=input
n=int(i())
a=i()
i=1
while i<n and a[i-1]<=a[i]:i+=1
print(a[:i-1]+a[i:])