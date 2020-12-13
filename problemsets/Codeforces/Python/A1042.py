"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
i=input
n=int(i())
m=int(i())
a=[int(i())for _ in[0]*n]
v=max(a)
u=sum(v-x for x in a)
print(max(0,0--(m-u)//n)+v,m+v)