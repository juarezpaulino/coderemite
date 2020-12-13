"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import string
n,k=map(int,input().split())
print((n*string.ascii_lowercase[:k])[:n])