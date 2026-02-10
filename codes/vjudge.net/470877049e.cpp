// 链接: https://vjudge.net/problem/HDU-1010
// 日期: 2026年01月31日

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
// #include <bits/stdc++.h>

using namespace std;

int slove();
int roundd = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (slove() != -1) { 
        roundd++;
    }
}

#define ll long long

int n, m, t;
int opx, opy;
int endd = false;
vector<vector<char>> mg;
map<int, map<int, bool>> vis;

bool visable(int x, int y) {
    if (x < 0 || x > n - 1) return false;
    if (y < 0 || y > m - 1) return false;
    if (vis[x][y]) return false;
    if (mg[x][y] == 'X') return false;
    return true;
}

void dfs(int x, int y, int time) {
    if (time > t || endd) return;
    int mms = abs(x - opx) + abs(y - opy);
    if (mms > t - time) return;
    if ((t - time - mms) % 2 == 1) return;
    if (time == t && x == opx && y == opy) {
        cout << "YES\n";
        endd = true;
        return;
    }
    if (visable(x + 1, y)) {
        vis[x + 1][y] = true;
        dfs(x + 1, y, time + 1);
        vis[x + 1][y] = false;
    }
    if (visable(x, y + 1)) {
        vis[x][y + 1] = true;
        dfs(x, y + 1, time + 1);
        vis[x][y + 1] = false;
    }
    if (visable(x - 1, y)) {
        vis[x - 1][y] = true;
        dfs(x - 1, y, time + 1);
        vis[x - 1][y] = false;
    }
    if (visable(x, y - 1)) {
        vis[x][y - 1] = true;
        dfs(x, y - 1, time + 1);
        vis[x][y - 1] = false;
    }
}

int slove() {
    cin >> n >> m >> t;
    mg = vector<vector<char>>(n, vector<char>(m));
    endd = false;
    vis.clear();

    int sx, sy;
    if (n + m + t == 0) return -1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            char c; cin >> c;
            mg[i][k] = c;
            if (c == 'S') {
                sx = i; sy = k;
            }
            if (c == 'D') {
                opx = i; opy = k;
            }
        }
    }
    vis[sx][sy] = true;
    dfs(sx, sy, 0);
    if (!endd) cout << "NO\n";

    return 1;
}