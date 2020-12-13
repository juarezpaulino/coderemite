"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
d,a,b,c,l=map(int,input().split())
r=0
while (r>0)*l+d>a:d-=a-(r>0)*l;a=min(a+c,b);r+=1
print(r+1)