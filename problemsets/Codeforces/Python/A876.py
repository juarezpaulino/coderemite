"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,a,b,c=map(int,''.join([*open(0)]).split())
a=min(a,b)
print((n>1)*a+(n>2)*(n-2)*min(a,c))