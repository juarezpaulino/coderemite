"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,a=int(input()),[]
for _ in range(n): a+=[sum(map(int,input().split()))]
print(1+sum(x>a[0] for x in a[1:]))