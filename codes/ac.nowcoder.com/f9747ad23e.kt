// 链接: https://ac.nowcoder.com/acm/contest/120565/B
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
    val n = nextInt()
    val m = nextInt()
    println(
        buildString {
            repeat(n) { line ->
                repeat(m) { index ->
                    if (line % 2 == 0) {
                        if (index % 2 == 0) append("/")
                        else append("\\")
                    } else {
                        if (index % 2 == 0) append("\\")
                        else append("/")
                    }
                }
                append('\n')
            }
        }
    )
}
