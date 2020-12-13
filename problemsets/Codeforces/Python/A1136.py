"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=[int(input().split()[1]) for _ in [0]*n ]
k=int(input())
print(n-sum(x<k for x in a))