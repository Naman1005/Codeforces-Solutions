fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val arr = Array(n) { i ->
            val cards = readLine()!!.split(" ").map { it.toInt() }.sorted()
            Cow(cards, i + 1) 
        }
        val brr = arr.sortedWith(Comparator { a: Cow, b: Cow ->
            for (i in 0 until m) {
                if (a.cards[i] != b.cards[i])
                    return@Comparator a.cards[i] - b.cards[i]
            }
            0
        })
        var flag = true
        for (i in 0 until n - 1) {
            for (r in 0 until m) {
                if (brr[i].cards[r] >= brr[i + 1].cards[r]) {
                    flag = false
                    break
                }
            }
            if (!flag) break
        }
        if (flag) {
            for (r in 1 until m) {
                if (brr[n - 1].cards[r - 1] >= brr[0].cards[r]) {
                    flag = false
                    break
                }
            }
        }
        if (!flag) {
            println("-1")
        } else {
            println(brr.joinToString(" ") { it.id.toString() })
        }
    }
}
 data class Cow(val cards: List<Int>, val id: Int)