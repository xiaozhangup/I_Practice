// 链接: https://codeforces.com/contest/2199/problem/B
// 日期: 2026年03月02日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.abs

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
                val a = nextInt()
                val b = nextInt()
                val c = nextInt()
                val d = nextInt()

                val minTarget = minOf(c, d)
                val maxCur = maxOf(a, b)

                if (minTarget > maxCur) {
                    appendLine(abs(a - b) + (minTarget - maxOf(a, b)) + abs(c - d))
                } else if (minTarget == maxCur) {
                    appendLine(abs(a - c) + abs(b - d))
                } else {
                    appendLine(abs(a - c) + abs(b - d))
                }
            }
        }
    )
}