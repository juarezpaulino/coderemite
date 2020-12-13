"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
i=input
a=i()
exec('b=['+'i(),'*10+']')
b=dict(zip(b,range(10)))
for i in range(0,len(a),10):
  print(b[a[i:i+10]],end='')