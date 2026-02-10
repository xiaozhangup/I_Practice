// 链接: https://codeforces.com/contest/2185/problem/E
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arra(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        arra[i] = a;
    }

    map<int, bool> arrb;
    for (int i = 1; i <= m; i++) {
        int b; cin >> b;
        arrb[b] = true;
    }

    int offset = 0;
    int lv = n;
    vector<bool> live(n + 1, true);
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        if (c == 'L') {
            offset--;
        } else if (c == 'R') {
            offset++;
        }

        for (int r = 1; r <= n; r++) {
            if (!live[r]) continue;
            int pos = arra[r] + offset;
            cout << pos;
            if (pos >= 1 && pos <= m) {
                if (arrb[pos]) {
                    live[r] = false;
                    lv--;
                }
            }
        }

        cout << lv << " ";
    }

    cout << "\n";
}