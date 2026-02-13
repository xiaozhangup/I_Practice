// 链接: https://ac.nowcoder.com/acm/contest/120566/A
// 日期: 2026年02月13日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.PriorityQueue
import java.util.StringTokenizer
import kotlin.math.hypot
import kotlin.math.sqrt

private val br = BufferedReader(InputStreamReader(System.`in`))
private var st: StringTokenizer? = null

private fun next(): String {
    while (st == null || !st!!.hasMoreElements()) {
        st = StringTokenizer(br.readLine())
    }
    return st!!.nextToken()
}

private fun nextInt() = next().toInt()
private fun nextLong() = next().toLong()
private fun nextDouble() = next().toDouble()
private fun nextFloat() = next().toFloat()
private fun nextLine(): String = br.readLine()
private fun nextChar(): Char = next()[0]

fun main() {
    val n = nextInt()
    var w = nextInt()
    val queue = PriorityQueue<Ruler>()

    var sum = 0.0
    repeat(n) {
        val x = nextInt()
        val y = nextInt()
        val ruler = Ruler(x, y)
        queue.offer(ruler)
        sum += cal(x, y)
    }

    while (w > 0 && queue.isNotEmpty()) {
        val ruler = queue.poll()
        sum -= ruler.saved
        ruler.y--
        w--

        ruler.saved = ruler.saved()
        if (ruler.y > 0) {
            queue.offer(ruler)
        }
    }

    println("%.10f".format(sum))
}

private class Ruler(
    var x: Int,
    var y: Int,
    var saved: Double
): Comparable<Ruler> {

    constructor(x: Int, y: Int): this(
        x, y, cal(x, y) - cal(x, y - 1)
    )

    fun saved(): Double {
        return cal(x, y) - cal(x, y - 1)
    }

    override fun compareTo(other: Ruler): Int {
        return other.saved.compareTo(saved)
    }
}

private fun cal(x: Int, y: Int): Double {
    return hypot(x.toDouble(), y.toDouble())
}
