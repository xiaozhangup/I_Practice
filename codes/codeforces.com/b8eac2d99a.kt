// 链接: https://codeforces.com/contest/2198/problem/F
// 日期: 2026年02月23日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.arraycopy
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
    fun lowerBound(arr: IntArray, target: Int): Int {
        var left = 0
        var right = arr.size
        while (left < right) {
            val mid = left + (right - left) / 2
            if (arr[mid] >= target) {
                right = mid
            } else {
                left = mid + 1
            }
        }
        return left
    }

    println(
        buildString {
            repeat(nextInt()) {
                val n = nextInt()
                val k = nextInt()
                val arrA = IntArray(n) { nextInt() }
                val arrB = IntArray(n) { nextInt() }

                arrA.sort()
                arrB.sort()

                val prices = IntArray(2 * n)
                arraycopy(arrA, 0, prices, 0, n)
                arraycopy(arrB, 0, prices, n, n)
                prices.sort()

                var max = 0L
                var last = -1
                for (p in prices) {
                    if (p == last) continue
                    last = p

                    val sumA = lowerBound(arrA, p)
                    val sumB = lowerBound(arrB, p)
                    val exp = sumA - sumB

                    if (exp <= k) {
                        val buy = n - sumB
                        val pro = p.toLong() * buy
                        max = max(max, pro)
                    }
                }

                appendLine(max)
            }
        }
    )
}