// 链接: https://ac.nowcoder.com/acm/contest/128672/E
// 日期: 2026年02月22日

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Queue
import java.util.StringTokenizer
import kotlin.math.min

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
    val queue = ArrayDeque<Int>()
    val vis = HashMap<Int, Int>()

    println(
        buildString {
            repeat(nextInt()) {
                val a = nextInt()
                val b = nextInt()
                val k = nextInt()

                if (a == b) {
                    append("0\n")
                    return@repeat
                }

                queue.clear()
                vis.clear()

                queue.add(a)
                vis[a] = 0

                while (queue.isNotEmpty()) {
                    val cur = queue.removeFirst()
                    val dep = vis[cur]!!

                    val k1 = cur + k
                    if (!vis.contains(k1) && k1 < 20000000) {
                        if (k1 == b) {
                            append(dep + 1)
                            append("\n")
                            return@repeat
                        }

                        vis[k1] = dep + 1
                        queue.add(k1)
                    }

                    fun reverse(n: Int): Int {
                        var temp = n
                        var reversed = 0

                        while (temp > 0) {
                            reversed = reversed * 10 + temp % 10
                            temp /= 10
                        }

                        return reversed
                    }

                    if (cur % 10 != 0) {
                        val k2 = reverse(cur)
                        if (!vis.contains(k2)) {
                            if (k2 == b) {
                                append(dep + 1)
                                append("\n")
                                return@repeat
                            }
                            vis[k2] = dep + 1
                            queue.add(k2)
                        }
                    }
                }

                append("-1\n")
            }
        }
    )
}
