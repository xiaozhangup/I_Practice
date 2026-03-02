// 链接: https://codeforces.com/contest/2199/problem/D
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
                val n = nextInt()
                val m = nextInt()

                val arrN = IntArray(n) { nextInt() }
                val arrM = IntArray(m) { nextInt() }

                val endA = if (n == 1) 0 else n - 2
                val endB = if (m == 1) 0 else m - 2

                var indexA = if (n == 1) 0 else 1
                var indexB = if (m == 1) 0 else 1
                var found = false

                while (indexA <= endA && indexB <= endB) {
                    val a = arrN[indexA]
                    val b = arrM[indexB]

                    if (a == b) {
                        found = true
                        break
                    } else if (a < b) {
                        indexA++
                    } else {
                        indexB++
                    }
                }

                if (found) appendLine("YES")
                else appendLine("NO")
            }
        }
    )
}