"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
input();a,*b=sorted(map(int,input().split()),reverse=True);print(sum(a-x for x in b))