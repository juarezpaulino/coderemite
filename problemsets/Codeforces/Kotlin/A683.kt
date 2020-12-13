private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
private fun Boolean.toInt() = if (this) 1 else 0
    
fun main(args: Array<String>) {
    var (a, x, y) = readInts()
    println("012"[(x<=0 || y<=0 || x>=a || y>=a).toInt() + (x<0 || y<0 || x>a || y>a).toInt()])
}