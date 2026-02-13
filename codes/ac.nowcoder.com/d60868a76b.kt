// 链接: https://ac.nowcoder.com/acm/contest/120566/G
// 日期: 2026年02月13日

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
    val n = nextInt()
    val m = nextInt()
    val l = nextInt()

    val escape = LongArray(n)
    repeat(n) {
        escape[it] = escape.getOrElse(it - 1) { 0 } + nextInt()
    }

    var cur = 0L
    var p = 0

    while (p < n && escape[p] <= 0) p++
    if (p < n && escape[p] < l) {
        println("YES")
        return
    }

    repeat(m) {
        cur += nextInt()
        while (p < n && escape[p] <= cur) p++

        if (p < n && escape[p] < cur + l) {
            println("YES")
            return
        }
    }

    println("NO")
}
