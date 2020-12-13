/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
var t = readline();
while (t--) {
  var n = readline();
  var a = readline().split(' ').map(Number);
  var b = new Set();
  var r = [];
  for (var e of a) if (!b.has(e)) r.push(e), b.add(e);
  print(...r);
}