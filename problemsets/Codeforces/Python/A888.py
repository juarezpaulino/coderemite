"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=*map(int,[*open(0)][1].split()),
print(sum((y-x)*(y-z)>0 for x,y,z in zip(a,a[1:],a[2:])))