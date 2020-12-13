"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a,b,c=map(int,input().split());d=a-b
print(0 if c==d==0 else '?' if c-abs(d)>=0 else '+' if d>0 else '-')