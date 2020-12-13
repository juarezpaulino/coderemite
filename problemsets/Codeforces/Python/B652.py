"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=sorted(map(int,input().split()))
a=[x for l in zip(a[:0--n//2],a[0--n//2:]) for x in l]+[a[n//2]]
print(*a[:n])