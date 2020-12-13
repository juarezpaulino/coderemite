"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
o=dict(zip('tminp',[0,1,1,2,3]))
a=sorted(enumerate([input().split()for _ in[0]*n]),key=lambda x:(o[x[1][1][2]],x[0]))
for x in a:print(x[1][0])
