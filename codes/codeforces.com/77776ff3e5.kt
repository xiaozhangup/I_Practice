// 链接: https://codeforces.com/contest/2199/problem/A
// 日期: 2026年03月02日

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
                val k = nextInt()

                val a1 = nextInt()
                val b1 = nextInt()
                val a2 = nextInt()
                val b2 = nextInt()

                val aTotal = a1 + a2 + 0
                val bTotal = b1 + b2 + k

                if (aTotal > bTotal) {
                    append("NO\n")
                } else if (aTotal == bTotal) {
                    var cot = 0
                    if (a1 > b1) cot++
                    if (a2 > b2) cot++
                    if (cot > 1) {
                        append("NO\n")
                    } else {
                        append("YES\n")
                    }
                } else {
                    append("YES\n")
                }
            }
        }
    )
}