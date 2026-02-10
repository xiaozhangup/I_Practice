// 链接: https://codeforces.com/contest/2185/problem/D
// 日期: 2026年01月26日

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
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> arra(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arra[i];
    }

    map<int, int> mod;
    for (int i = 1; i <= m; i++) {
        int b, c;
        cin >> b >> c;
        mod[b] += c;
        if (arra[b] + mod[b] > h) {
            mod.clear();
        }
    }

    for (auto pa : mod) {
        int b = pa.first;
        int c = pa.second;
        arra[b] += c;
    }

    for (int i = 1; i <= n; i++) {
        cout << arra[i];
        if (i != n) cout << " ";
    }

    cout << "\n";
}