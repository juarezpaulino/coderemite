"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=['purple', 'green', 'blue', 'orange', 'red', 'yellow']
b=['Power', 'Time', 'Space', 'Soul', 'Reality', 'Mind']
n=int(input())
c=[input() for _ in [0]*n]
d=[b[x] for x,y in enumerate(a) if y not in c]
print(len(d),*d,sep='\n')