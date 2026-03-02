// 链接: https://codeforces.com/contest/2199/problem/C
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

                if (k == 1) {
                    appendLine("YES")
                    appendLine(1)
                    appendLine("*")
                    appendLine(".")
                    return@repeat
                }

                val rem = k % 5
                if (rem == 2 || rem == 4) {
                    appendLine("NO")
                } else {
                    appendLine("YES")

                    var line1 = ""
                    when(rem) {
                        0 -> {
                            line1 = ".*.".repeat(k / 5)
                        }
                        1 -> {
                            val num = (k - 6) / 5
                            line1 += "*."
                            line1 += ".*.".repeat(num)
                            line1 += ".*"
                        }
                        3 -> {
                            val num = (k - 3) / 5
                            line1 += "*."
                            line1 += ".*.".repeat(num)
                        }
                    }

                    appendLine(line1.length)
                    appendLine(line1)
                    appendLine(".".repeat(line1.length))
                }
            }
        }
    )
}