"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
from decimal import *
getcontext().prec=1000
a=input()
x=a.split('.')[0][-1]
print([int(Decimal(a)+Decimal(0.5)),'GOTO Vasilisa.'][x=='9'])