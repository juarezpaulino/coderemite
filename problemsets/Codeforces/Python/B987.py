"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import math
x,y=map(lambda x:math.log(int(x))/int(x),input().split())
print('<=>'[(x>=y)+(x>y)])