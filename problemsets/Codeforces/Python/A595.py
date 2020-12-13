"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import re
n,m=map(int,input().split());r=0
for _ in [0]*n:
  r += sum(1 for x in re.split('(\d \d)',input()) if x.count('1')) 
print(r)