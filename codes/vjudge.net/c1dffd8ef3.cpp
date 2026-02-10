// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1387
// 日期: 2026年01月25日

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

void slove();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

int n, m;
vector<vector<int>> mm;

bool isVaid(int x, int y, int size) {
    if (x + size - 1 > n) return false;
    if (y + size - 1 > m) return false;

    return size * size == (mm[x + size - 1][y + size - 1] + mm[x - 1][y - 1] - mm[x - 1][y + size - 1] - mm[x + size - 1][y - 1]);
}

void slove() {
    cin >> n >> m;
    int gea = min(n, m);
    mm = vector(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) { // hang
        for (int k = 1; k <= m; k++) { // lie
            int bo; cin >> bo;
            mm[i][k] = bo + mm[i - 1][k] + mm[i][k - 1] - mm[i - 1][k - 1];
        }
    }

    int ma = 1;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            for (int s = ma + 1; s <= gea; s++) {
                if (isVaid(x, y, s)) {
                    ma = s;
                } else {
                    break;
                }
            }
        }
    }

    cout << ma;

}