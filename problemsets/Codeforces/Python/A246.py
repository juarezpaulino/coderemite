"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
print(*[[2,2]+[1]*(n-2),[-1]][n<3])