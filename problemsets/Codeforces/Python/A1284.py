"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=map(int,input().split())
a,b=(input().split(),input().split())
for _ in range(int(input())):
  x=int(input())-1
  print(a[x%n],b[x%m],sep='')