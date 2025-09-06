fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val ctr = s.groupingBy { it }.eachCount()
    if (ctr.any { it.value > 1 } || ctr.size == 1) println("Yes")
    else println("No")
}