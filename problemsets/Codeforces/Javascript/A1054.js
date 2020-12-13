/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
a = readline().split(' ').map(Number)
x = a[0]
y = a[1]
z = a[2]
t1 = a[3]
t2 = a[4]
t3 = a[5]
print(t1*Math.abs(x-y)<t2*Math.abs(x-y)+3*t3+t2*Math.abs(x-z)?"NO":"YES")