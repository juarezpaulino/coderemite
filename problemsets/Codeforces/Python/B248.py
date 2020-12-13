"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
s=input()
a=s.count('A')
i=s.count('I')
print([[a,1][i==1],0][i>1])