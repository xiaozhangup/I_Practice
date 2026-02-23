// 链接: https://codeforces.com/contest/2198/problem/D
// 日期: 2026年02月23日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.min

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
                val num = next()
                var sum = 0
                var other2 = 0
                var other6 = 0

                for (c in num) {
                    sum += c - '0'
                    if (c == '2') other2++
                    else if (c == '3') other6++
                }

                var succ = false
                val rem = sum % 9
                if (rem == 0) succ = true
                for (c2 in 0..min(9, other2)) {
                    for (c6 in 0..min(3, other6)) {
                        if ((rem + c2 * 2 + c6 * 6) % 9 == 0) {
                            succ = true
                            break
                        }
                    }
                }

                appendLine(
                    if (succ) "YES" else "NO"
                )
            }
        }
    )
}