"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:[*map(int,input().split())]
d={}
exec(2*'for _ in[0]*I()[0]:\n a,b=I()\n if a in d:d[a]=max(d[a],b)\n else:d[a]=b\n')
print(sum(d.values()))