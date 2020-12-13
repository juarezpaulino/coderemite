"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
print(*[256*e+32*min(b,a-e) for a,b,c,d in [map(int,input().split())] for e in [min(a,c,d)]])