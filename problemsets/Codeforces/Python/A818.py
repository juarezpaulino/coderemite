"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
d=n//(2*k+2)
print(d,d*k,n-d-d*k)