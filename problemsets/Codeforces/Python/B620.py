"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
s=[6,2,5,5,4,5,6,3,7,6]
a,b=map(int,input().split())
t=''.join(map(str,range(a,b+1)))
print(sum(s[d]*t.count(str(d))for d in range(10)))