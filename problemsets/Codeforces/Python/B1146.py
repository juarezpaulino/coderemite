"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
b=a.replace('a','')
x=len(b)//2
if len(b)<1: print(a)
else: print([a[:-x],':('][b[:-x]!=b[-x:] or a[-x:].count('a')>0])
