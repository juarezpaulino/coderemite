/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
var t = readline()
while (t--) {
  var a = readline().split(' ')
  var l = +a[0]
  var r = +a[1]
  print(r < 2 * l ? '-1 -1' : [l, 2 * l].join(' '))
}