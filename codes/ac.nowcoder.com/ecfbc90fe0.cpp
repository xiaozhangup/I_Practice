// 链接: https://ac.nowcoder.com/acm/contest/120561/D
// 日期: 2026年02月03日

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

#define int long long

int n, k, white;
vector<int> a;
vector<int> pos;
vector<int> reach;

bool check(int mid) {
    int cnt = 0;
    int lastReach = -1;

    for (int i = 0; i < white; i++) {
        if (pos[i] > lastReach) {
            cnt++;
            lastReach = reach[i];
            if (cnt > mid) return false;
        } else {
            if (reach[i] > lastReach) {
                lastReach = reach[i];
            }
        }
    }

    return cnt <= mid;
}

void slove() {
    cin >> n >> k;
    white = 0;
    a.resize(n + 1);
    pos.clear(); reach.clear();

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            white++;
            pos.push_back(i);
            reach.push_back(i + a[i]);
        }
    }

    if (white == 0) {
        cout << "0\n";
        return;
    }

    int l = 0, r = white;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}