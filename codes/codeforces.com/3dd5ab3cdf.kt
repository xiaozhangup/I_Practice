// 链接: https://codeforces.com/contest/2198/problem/E
// 日期: 2026年02月23日

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
    println(
        buildString {
            repeat(nextInt()) {
                val n = nextInt()
                val m1 = nextInt()
                val m2 = nextInt()

                repeat(m1) { // F
                    val u = nextInt()
                    val v = nextInt()
                }

                repeat(m2) { // G
                    val u = nextInt()
                    val v = nextInt()
                }
            }
        }
    )
}