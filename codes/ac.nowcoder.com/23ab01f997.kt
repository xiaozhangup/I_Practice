// 链接: https://ac.nowcoder.com/acm/contest/120566/D
// 日期: 2026年02月13日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Queue
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

private val offset = listOf(1 to 0, 0 to 1, -1 to 0, 0 to -1)

fun main() {
    val n = nextInt()
    val m = nextInt()
    val a = nextInt()
    val b = nextInt()

    fun asLoc(x: Int, y: Int): Int {
        return x * m + y
    }

    val timer = Array(m * n) { Int.MAX_VALUE }
    val queue = ArrayDeque<Pair<Int, Int>>()
    repeat(a) {
        val x = nextInt() - 1
        val y = nextInt() - 1
        queue.add(x to y)
        timer[asLoc(x, y)] = 1
    }

    repeat(b) {
        val x = nextInt() - 1
        val y = nextInt() - 1
        val v = nextInt() * -1
        timer[asLoc(x, y)] = v
    }

    while (!queue.isEmpty()) {
        val cur = queue.removeFirst()
        for (ne in offset) {
            val curx = cur.first
            val cury = cur.second

            val nx = curx + ne.first
            val ny = cury + ne.second
            if (nx < 0 || nx > n - 1) continue
            if (ny < 0 || ny > m - 1) continue

            if (timer[asLoc(nx, ny)] == Int.MAX_VALUE) {
                timer[asLoc(nx, ny)] = timer[asLoc(curx, cury)] + 1
                queue.add(nx to ny)
            } else if (timer[asLoc(nx, ny)] < 0) {
                val unlockTime = -timer[asLoc(nx, ny)]
                val arrivalRealTime = timer[asLoc(curx, cury)]
                val finalRealTime = max(arrivalRealTime, unlockTime)

                timer[asLoc(nx, ny)] = finalRealTime + 1
                queue.add(nx to ny)
            }
        }
    }

    println(timer.maxOf { it } - 2)
}