"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=sorted(map(int,input().split()))
print(min([sum(abs(x-y)for x,y in zip(a,range(i,n+1,2)))for i in[1,2]]))