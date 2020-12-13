"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=sorted(map(int,input().split()))
print(sum(a[i]-a[i-1] for i in range(1,n,2)))