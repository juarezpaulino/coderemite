"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a,b=int(input()),int(input())
print(*[*range(b+1,a+b+2),*range(b,0,-1)])