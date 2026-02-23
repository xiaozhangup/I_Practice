// 链接: https://codeforces.com/contest/2198/problem/C
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
                val m = nextInt()
                val k = nextInt()

                val absent = IntArray(m) { nextInt() }
                val known = BooleanArray(n + 1)
                repeat(k) {
                    known[nextInt()] = true
                }

                repeat(m) { i ->
                    when (k) {
                        n -> append(1)
                        n - 1 if !known[absent[i]] -> append(1)
                        else -> append(0)
                    }
                }

                append('\n')
            }
        }
    )
}