"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=sorted(map(int,input().split()))
k=0
while k*10+2*sum(a[k:])<9*n:k+=1
print(k)