// 链接: https://ac.nowcoder.com/acm/contest/120566/H
// 日期: 2026年02月13日

import java.io.BufferedReader
import java.io.InputStreamReader
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
    val n = nextInt()
    var x = 0

    val arrayA = IntArray(n) { nextInt() }
    val arrayB = IntArray(n) { nextInt() }

    var len = BooleanArray(2048)
    len[0] = true

    repeat(n) { index ->
        val next = BooleanArray(2048)
        repeat(2048) { i ->
            if (!len[i]) return@repeat

            next[max(0, i - arrayA[index])] = true
            next[i xor arrayB[index]] = true
        }
        len = next
    }


    println(len.indexOfLast { it })
}
