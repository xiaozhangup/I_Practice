// 链接: https://ac.nowcoder.com/acm/contest/120565/D
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

private const val MOD = 1_000_000_007L

fun main() {
    val map = sortedMapOf<Long, Long>() // weight, amount
    repeat(nextInt()) {
        val c = nextLong()
        val w = nextLong()
        map[w] = map.getOrDefault(w, 0L) + c
    }

    var res = 0L
    var left = false
    var left_w = 0L

    while (map.isNotEmpty()) {
        val w = map.firstKey()
        var cur = map.remove(w)!!

        if (left) {
            val nw = left_w + w
            res += nw
            res %= MOD

            map[nw] = map.getOrDefault(nw, 0L) + 1
            cur--
            left = false
        }
        if (cur <= 0L) continue

        val pr = cur / 2
        if (pr > 0) {
            val nw = w * 2
            res += (pr % MOD) * (nw % MOD)
            res %= MOD
            map[nw] = map.getOrDefault(nw, 0L) + pr
        }

        if (cur % 2 == 1L) {
            left_w = w
            left = true
        }
    }

    println(res)
}
