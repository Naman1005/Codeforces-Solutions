import java.io.*
 fun ask(l: Long, r: Long): Long {
    println("? $l $r")
    System.out.flush()
    return readLine()!!.toLong()
}
 fun click_clack_boom() {
    val n = readLine()!!.toInt()
    var p = -1
    var x = 0L
    var y = 0L
    for (i in 1 until n) {
        x = ask(1, (i + 1).toLong())
        if (x > 0) {
            p = i
            break
        }
    }
    if (p == -1) {
        println("! IMPOSSIBLE")
        System.out.flush()
        return
    }
    val ans = CharArray(n) { '1' }
    for (i in (p - 1) downTo (p - x.toInt())) {
        ans[i] = '0'
    }
    for (i in p + 1 until n) {
        y = ask(1, (i + 1).toLong())
        ans[i] = if (y > x) '1' else '0'
        x = y
    }
    println("! ${String(ans)}")
    System.out.flush()
}
 fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        click_clack_boom()
    }
}