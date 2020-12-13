"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import re
print(max(len({*x})for x in re.split('[A-Z\n]',[*open(0)][1])))