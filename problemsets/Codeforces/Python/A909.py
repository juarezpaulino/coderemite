"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input().split()
i=1
while i<len(a[0]) and a[0][i]<a[1][0]:i+=1
print(a[0][:i]+a[1][0])