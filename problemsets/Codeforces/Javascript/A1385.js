/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
var t = readline()
while (t--) {
  var a = readline().split(' ').sort((x, y) => +y - x)
  var x = +a[0]
  var y = +a[1]
  var z = +a[2]
  if (x !== y) print('NO')
  else {
    print('YES')
    print(x, z, 1)
  }
}