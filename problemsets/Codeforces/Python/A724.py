"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
w=["mo","tu","we","th","fr","sa","su"]
exec('a,b=['+2*'w.index(input()[:2]),'+']')
print('YNEOS'[all((a+x)%7!=b for x in[0,2,3])::2])
