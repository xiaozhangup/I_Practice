// 链接: https://codeforces.com/contest/2198/problem/B
// 日期: 2026年02月23日

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
    println(
        buildString {
            repeat(nextInt()) {
                val a1 = nextInt()
                val a2 = nextInt()
                val a4 = nextInt()
                val a5 = nextInt()

                val set = mutableSetOf<Int>()
                set += a1 + a2
                set += a4 - a2
                set += a5 - a4
                appendLine(4 - set.size)
            }
        }
    )
}
