fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toLong() 
        val s = readLine()!!
        var c1 = 0L 
        var c2 = 0L 
        for (c in s) {
            if (c == '-') {
                c1++
            } else {
                c2++
            }
        }
        if (c1 < 2 || c2 < 1) {
            println(0)
        } else {
            val left = c1 / 2
            val right = c1 - left
            println(left * c2 * right)
        }
    }
}