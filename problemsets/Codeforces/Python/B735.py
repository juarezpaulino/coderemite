"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,u,v=map(int,input().split())
if u>v:u,v=v,u
a=sorted(map(int,input().split()))[::-1]
print(sum(a[:u])/u+sum(a[u:u+v])/v)