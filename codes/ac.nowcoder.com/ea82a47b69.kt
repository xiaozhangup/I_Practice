// 链接: https://ac.nowcoder.com/acm/contest/120564/I
// 日期: 2026年02月11日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

private val br = BufferedReader(InputStreamReader(System.`in`))
private var st: StringTokenizer? = null

fun next(): String {
    while (st == null || !st!!.hasMoreElements()) {
        st = StringTokenizer(br.readLine())
    }
    return st!!.nextToken()
}

fun nextInt() = next().toInt()
fun nextLong() = next().toLong()

fun main() {
    println("######")
}
