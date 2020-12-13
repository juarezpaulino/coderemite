"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import re
input()
a=[len(x) for x in re.split('[^B]',input()) if x]
print(len(a))
print(*a)
