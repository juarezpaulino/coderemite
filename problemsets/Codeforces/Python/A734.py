"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,a=int(input()),input().count('A')
print(["Anton","Danik","Friendship"][2 if a*2==n else a*2<n])