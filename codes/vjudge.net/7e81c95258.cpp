// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1706
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
#include <iomanip>
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

int n;
int path[15];
int vis[15];

void dfs(int step) {
    if (step > n) {
        for (int i = 1; i<= n; i++) {
            cout << setw(5) << path[i];
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            path[step] = i;
            vis[i] = true;
            dfs(step + 1);
            vis[i] = false;
        }
    }
}

void slove() {
    cin >> n;
    dfs(1);
}