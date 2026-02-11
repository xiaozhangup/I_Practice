// 链接: https://ac.nowcoder.com/acm/contest/120565/J
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
    val map = Array(3) { IntArray(3) }
    val dup = mutableSetOf<Int>()
    repeat(3) { line ->
        repeat(3) { colum ->
            val num = nextInt()
            map[line][colum] = num
            if (dup.contains(num)) {
                println("No")
                return
            }
            dup.add(num)
        }
    }

    val tar = map[0].sumOf { it }
    for (l in map) {
        if (l.sumOf { it } != tar) {
            println("No")
            return
        }
    }
    for (c in 0..2) {
        val su = map[0][c] + map[1][c] + map[2][c]
        if (su != tar) {
            println("No")
            return
        }
    }

    val r1 = map[0][0] + map[1][1] + map[2][2]
    val r2 = map[0][2] + map[1][1] + map[2][0]
    if (r1 == r2 && tar == r1) {
        println("Yes")
    } else {
        println("No")
    }
}
