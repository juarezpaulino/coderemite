"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,h=map(int,input().split())
print(n+sum(int(p)>h for p in input().split()))