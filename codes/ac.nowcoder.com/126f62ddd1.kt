// 链接: https://ac.nowcoder.com/acm/contest/120565/A
// 日期: 2026年02月11日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.math.BigInteger
import java.util.StringTokenizer
import kotlin.math.ceil
import kotlin.math.max
import kotlin.math.sqrt

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

private const val MOD = 1_000_000_007L

private fun qpow10(exp: Long): Long {
    var base = 10L
    var e = exp
    var result = 1L
    while (e > 0) {
        if (e and 1L == 1L) {
            result = result * base % MOD
        }
        base = base * base % MOD
        e = e shr 1
    }
    return result
}

fun main() {
    println(
        buildString {
            repeat(nextInt()) {
                val pos = nextLong()
                if (pos <= 3L) {
                    when (pos) {
                        1L -> append(1)
                        2L -> append(10)
                        3L -> append(11)
                        else -> throw Throwable("?")
                    }
                } else {
                    val x = pos - 4
                    val vs = x / 3 + 1
                    val type = x % 3
                    var res = when(type) {
                        0L -> 10L
                        1L -> 10L
                        2L -> 11L
                        else -> throw Throwable("?")
                    }

                    res = res * qpow10(vs) % MOD

                    if (type == 1L) {
                        res = (res + 1) % MOD
                    }

                    append(res)
                }

                append("\n")
            }
        }
    )
}
