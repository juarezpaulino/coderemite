"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
print(len({*range(1,n+1)}-{*map(int,input().split())}))
