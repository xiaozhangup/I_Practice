// 链接: https://ac.nowcoder.com/acm/contest/120564/A
// 日期: 2026年02月11日

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
    val counter = mutableMapOf<Int, Int>()
    val arr = mutableSetOf<Int>()
    repeat(n) {
        val num = nextInt()
        counter[num] = counter.getOrDefault(num, 0) + 1
        arr.add(num)
    }

    var suma = 0
    var sumb = 0
    for (i in arr) {
        val per = 1.0 * (arr.sumOf {
            if (it <= i) counter[it]!! else 0
        } - 1) / (n - 1)
        if (per >= 0.8) {
            suma += counter[i]!! * i
        } else {
            sumb += counter[i]!! * i
        }
    }

    println(suma)
}
