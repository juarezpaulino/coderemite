"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a,b=map(int,input().split())
print(['[:=[first]','[second]=:]'][(a*b)%2])