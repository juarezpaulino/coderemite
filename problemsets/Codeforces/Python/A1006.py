"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
input()
print(*[x if x%2 else x-1 for x in map(int,input().split())])