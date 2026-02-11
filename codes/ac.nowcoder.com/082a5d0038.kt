// 链接: https://ac.nowcoder.com/acm/contest/120565/G
// 日期: 2026年02月11日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

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
    val act = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532"
    val map = arrayOf(
        intArrayOf(3, 0, 1, 2, 1, 3),
        intArrayOf(2, 3, 0, 1, 2, 0),
        intArrayOf(1, 2, 3, 0, 3, 1),
        intArrayOf(0, 1, 2, 3, 0, 2)
    )
    println(
        buildString {
            var last = 0
            for (c in act) {
                last = map[last][c - '0']
                append(last)
            }
        }
    )
}
