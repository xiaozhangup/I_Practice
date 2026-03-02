// 链接: https://codeforces.com/contest/2199/problem/H
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
    val mod = 998244353
    val size = 302
    println(
        buildString {
            val n = nextInt()
            val arr = IntArray(n) { nextInt() }

            val com = Array(size) { LongArray(size) }
            for (i in 0..size) {
                com[i][0] = 1L
                for (j in 1..i) {
                    com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % mod
                }
            }


        }
    )
}

private fun qpow(base: Long, exp: Long, mod: Long): Long {
    var result = 1L
    var b = base % mod
    var e = exp
    while (e > 0) {
        if (e and 1L == 1L) {
            result = (result * b) % mod
        }
        b = (b * b) % mod
        e = e shr 1
    }
    return result
}