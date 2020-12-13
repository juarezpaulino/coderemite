"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=map(int,input().split())
print(*[n//m]*(m-n%m)+[n//m+1]*(n%m))