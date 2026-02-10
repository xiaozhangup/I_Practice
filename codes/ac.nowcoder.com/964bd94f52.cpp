// 链接: https://ac.nowcoder.com/acm/contest/120564/H
// 日期: 2026年02月09日

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

#define int long long

vector<vector<int>> mapping(510, vector<int>(510, 0));
int n, m, q;

int offx[] = {0, 0, 0, 1, -1, 1, 1, -1, -1, 0, 0, 2, -2};
int offy[] = {0, 1, -1, 0, 0, 1, -1, 1, -1, 2, -2, 0, 0};

bool isin(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int grab(int x, int y) {
    if (!isin(x, y)) return -1;

    int sum = 0;
    for (int i = 0; i < 13; i++) {
        int nx = x + offx[i];
        int ny = y + offy[i];
        if (isin(nx, ny)) {
            sum += mapping[nx][ny];
        }
    }

    return sum;
}

void slove() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mapping[i][j];
        }
    }

    int maxx = 1, maxy = 1;
    int bigg = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int g = grab(i, j);
            if (g > bigg) {
                bigg = g;
                maxx = i;
                maxy = j;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        int z; cin >> z;
        mapping[x][y] += z;

        for (int i = 0; i < 13; i++) {
            int ox = x + offx[i];
            int oy = y + offy[i];
            
            int gs = grab(ox, oy);
            if (gs > bigg) {
                bigg = gs;
                maxx = ox;
                maxy = oy;
            }
        }
        
        cout << maxx << " " << maxy << "\n";
    }
}