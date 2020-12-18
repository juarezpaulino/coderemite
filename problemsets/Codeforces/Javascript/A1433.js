/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
var t = readline()
while (t--) {
  var x = readline()
  var r = 10 * (+x[0] - 1) + [0, 1, 3, 6, 10][x.length];
  print(r)
}