// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1135
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

vector<int> fls;

void slove() {
    int n, a, b; cin >> n >> a >> b;
    fls = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        fls[i] = k;
    }

    queue<int> flor;
    vector<int> vis(n + 1);
    flor.push(a);
    vis[a] = 0;
    while (!flor.empty())
    {
        int w = flor.front(); flor.pop();
        if (w == b) {
            cout << vis[b];
            return;
        }

        int act = fls[w];
        if (w + act <= n && !vis[w + act]) {
            flor.push(w + act);
            vis[w + act] = vis[w] + 1;
        }
        if (w - act >= 1 && !vis[w - act]) {
            flor.push(w - act);
            vis[w - act] = vis[w] + 1;
        }
    }
    
    cout << -1;
}