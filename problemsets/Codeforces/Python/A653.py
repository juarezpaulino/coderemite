"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=sorted({*map(int,[*open(0)][1].split())})
print('NYOE S'[any(x+1==y==z-1 for x,y,z in zip(a,a[1:],a[2:]))::2])
