/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
var t = readline();
while (t--) {
  var b = readline();
  var a = b[0];
  for (var i = 1; i < b.length; i += 2) a += b[i];
  print(a);
}