// 链接: https://ac.nowcoder.com/acm/contest/120566/E
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
    val x = nextInt()
    val d = nextInt()

    val citys = Array(n) { City(0, 0) }
    repeat(n) { id ->
        val h = nextInt()
        citys[id] = City(id, h)
    }
    repeat(m) {
        val u = nextInt()
        val v = nextInt()
        citys[u - 1].linked.add(citys[v - 1])
        citys[v - 1].linked.add(citys[u - 1])
    }

    val levels = IntArray(x) { nextInt() }
    val scitys = citys.sortedByDescending { it.height }
    val res = IntArray(x)
    var linked = 0

    val parent = IntArray(n) { it }
    val chunk = IntArray(n) { 1 }
    fun find(i: Int): Int {
        var root = i
        while (parent[root] != root) {
            root = parent[root]
        }
        var cur = i
        while (cur != root) {
            val next = parent[cur]
            parent[cur] = root
            cur = next
        }
        return root
    }

    fun union(i: Int, j: Int) {
        val rootI = find(i)
        val rootJ = find(j)
        if (rootI != rootJ) {
            if (chunk[rootI] >= d) linked--
            if (chunk[rootJ] >= d) linked--

            parent[rootJ] = rootI
            chunk[rootI] += chunk[rootJ]

            if (chunk[rootI] >= d) linked++
        }
    }

    var poi = 0
    for (day in x - 1 downTo 0) {
        val level = levels[day]

        while (poi < n && scitys[poi].height > level) {
            val city = scitys[poi]
            val id = city.id

            city.active = true
            if (chunk[id] >= d) {
                linked++
            }

            for (neighbor in city.linked) {
                if (neighbor.active) {
                    union(id, neighbor.id)
                }
            }

            poi++
        }

        res[day] = linked
    }

    println(res.joinToString("\n"))
}

private data class City(
    val id: Int,
    val height: Int,
    val linked: ArrayList<City> = ArrayList(),
    var active: Boolean = false
)