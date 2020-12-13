"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=map(int,input().split())
a=[]
if m:a+=sorted(map(int,input().split()))
print('YNEOS'[any(x in a for x in[1,n])or any(x+1==y==z-1 for x,y,z in zip(a,a[1:],a[2:]))::2])