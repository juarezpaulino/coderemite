"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in[*open(0)][1:]:a,b=map(int,s.split())print('YNEOS'[a+b<a*b::2])
exec(int(input())*"n,m=map(int,input().split());print('YNEOS'[n+m<n*m::2]);")