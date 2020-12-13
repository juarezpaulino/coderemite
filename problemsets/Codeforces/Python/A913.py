"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
R = lambda:list( map(int, input().split()) )
n, m = R()[0], R()[0]
print(m if n >= 30 else m%(1<<n))