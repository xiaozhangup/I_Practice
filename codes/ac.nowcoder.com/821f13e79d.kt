// 链接: https://ac.nowcoder.com/acm/contest/120565/F
// 日期: 2026年02月11日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.max

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
    println(buildString {
        repeat(nextInt()) {
            val n = nextLong()
            val a = nextLong() // len 7
            val b = nextLong() // len 2
            val c = a + b // len 8

            val items = arrayOf(
                a to 7L,
                b to 2L,
                c to 8L
            ).sortedByDescending { it.first.toDouble() / it.second }

            val (i1, w1) = items[0]
            val (i2, w2) = items[1]
            val (i3, w3) = items[2]

            var res = 0L

            for (l1 in 0L..minOf(n / w1, w2 * w3)) {
                val g1 = n / w1 - l1
                val rem1 = n - g1 * w1

                for (l2 in 0L..minOf(rem1 / w2, w3)) {
                    val g2 = rem1 / w2 - l2
                    val rem2 = rem1 - g2 * w2
                    val g3 = rem2 / w3

                    res = max(res, g1 * i1 + g2 * i2 + g3 * i3)
                }
            }

            append(res)
            append("\n")
        }
    })
}