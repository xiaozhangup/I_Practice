// 链接: https://codeforces.com/contest/2198/problem/A
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
                val map = mutableMapOf<Int, Int>()
                repeat(n) {
                    val i = nextInt()
                    map[i] = map.getOrDefault(i, 0) + 1
                }

                var sum = 0
                for (p in map) {
                    sum += p.value / 2
                }
                appendLine(sum)
            }
        }
    )
}
