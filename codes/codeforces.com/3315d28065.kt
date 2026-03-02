// 链接: https://codeforces.com/contest/2199/problem/E
// 日期: 2026年03月02日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Arrays
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
            val n = nextInt()
            val q = nextInt()
            val arr = IntArray(n) { nextInt() }

            val pos = LongArray(n)
            pos[0] = 1L

            for (i in 0 until n - 1) {
                val dis = abs(arr[i + 1] - arr[i])
                if (dis == 0) {
                    pos[i + 1] = pos[i] + 2
                } else {
                    pos[i + 1] = pos[i] + dis
                }
            }

            val length = pos[n - 1]
            for (i in 0 until q) {
                val x = nextLong()
                if (x > length) {
                    append("-1 ")
                } else {
                    val id = Arrays.binarySearch(pos, x)

                    if (id >= 0) {
                        append(arr[id]).append(" ")
                    } else {
                        val bp = -id - 1
                        val ind = bp - 1
                        val offset = x - pos[ind]

                        val start = arr[ind]
                        val end = arr[ind + 1]

                        if (start == end) {
                            append("0 ")
                        } else {
                            if (start < end) {
                                append(start + offset).append(" ")
                            } else {
                                append(start - offset).append(" ")
                            }
                        }
                    }
                }
            }
        }
    )
}