import java.io.BufferedReader
import java.io.InputStreamReader
 fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val t = reader.readLine().toInt()
    repeat(t) {
        val (n, x, y) = reader.readLine().split(" ").map { it.toLong() }
        val a = reader.readLine().split(" ").map { it.toLong() }.toLongArray()
        val S = a.sum()
        val L = S - y
        val R = S - x
        a.sort()
        println(solve(a, R) - solve(a, L - 1))
    }
}
fun solve(a: LongArray, bound: Long): Long {
    var count: Long = 0
    var l = 0
    var r = a.size - 1
    while (l < r) {
        if (a[l] + a[r] <= bound) {
            count += (r - l).toLong()
            l++
        } else {
            r--
        }
    }
    return count
}