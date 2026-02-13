// 链接: https://ac.nowcoder.com/acm/contest/120566/B
// 日期: 2026年02月13日

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

private const val mod = 998244353

fun main() {
    println(buildString {
        repeat(nextInt()) {
            val n = nextInt()
            val x = nextInt()
            val t = nextInt()

            

            append("\n")
        }
    })
}
