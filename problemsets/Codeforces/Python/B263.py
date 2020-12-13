"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
a=sorted(map(int,input().split()))
print(*(k>n and[-1]or[a[-k]]*2))