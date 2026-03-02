// 链接: https://codeforces.com/contest/2199/problem/F
// 日期: 2026年03月03日

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
    val mod = 998244353L
    val max = 200005

    val pow2 = LongArray(max + 1)
    pow2[0] = 1L

    val invPow2 = LongArray(max + 1)
    invPow2[0] = 1L

    val inv2 = 499122177L
    for (i in 1..max) {
        pow2[i] = (pow2[i - 1] * 2) % mod
        invPow2[i] = (invPow2[i - 1] * inv2) % mod
    }

    println(
        buildString {
            repeat(nextInt()) {
                val n = nextInt()
                val arr = IntArray(n) { nextInt() }

                val prefix = IntArray(n + 1)
                var count = 0

                val pack = LongArray(n)
                for (i in 0 until n) {
                    val v = arr[i].toLong()
                    pack[i] = (v shl 32) or i.toLong()
                    prefix[i] = count
                    if (v == 0L) count++
                }
                prefix[n] = count

                var res = pow2[count]
                pack.sort()

                var i = 0
                while (i < n) {
                    val ind = pack[i]
                    val v = (ind ushr 32).toInt()

                    if (v == 0) {
                        i++
                        continue
                    }

                    var j = i
                    while (j < n && (pack[j] ushr 32).toInt() == v) {
                        j++
                    }

                    val len = j - i
                    if (len > 1) {
                        var sum = 0L

                        for (k in i until j) {
                            val id = pack[k].toInt()
                            val term = invPow2[prefix[id + 1]]
                            val cont = (sum * term) % mod

                            val total = (cont * pow2[count]) % mod
                            res += total
                            res %= mod

                            sum += pow2[prefix[id]]
                            sum %= mod
                        }
                    }

                    i = j
                }
                appendLine(res)
            }
        }
    )
}