"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=int(input()),0
for _ in '0'*n:
  a,b=map(int,input().split())
  m+=[[1,-1][a<b],0][a==b]
print([['Mishka','Chris'][m<0],'Friendship is magic!^^'][m==0])