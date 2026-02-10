// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1314
// 日期: 2026年01月27日

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

ll s;
ll ans = 9e18;
vector<int> arrw, arrv;
vector<pair<int, int>> arrr;

vector<int> sum_n;
vector<ll> sum_v;

bool check(int W) {
    int n = arrw.size() - 1;
    
    sum_n.assign(n + 1, 0);
    sum_v.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        if (arrw[i] >= W) {
            sum_n[i] = sum_n[i - 1] + 1;
            sum_v[i] = sum_v[i - 1] + arrv[i];
        } else {
            sum_n[i] = sum_n[i - 1];
            sum_v[i] = sum_v[i - 1];
        }
    }

    ll Y = 0;
    for (auto pa : arrr) {
        int l = pa.first;
        int r = pa.second;
        ll cnt = sum_n[r] - sum_n[l - 1];
        ll val = sum_v[r] - sum_v[l - 1];
        
        Y += cnt * val;
    }

    ans = min(ans, abs(Y - s));
    return Y > s;
}

void slove() {
    int n, m; 
    cin >> n >> m >> s;

    arrw = vector<int>(n + 1);
    arrv = vector<int>(n + 1);
    arrr.resize(m);
    int max_w = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arrw[i] >> arrv[i];
        max_w = max(max_w, arrw[i]);
    }
    
    for (int i = 0; i < m; i++) {
        cin >> arrr[i].first >> arrr[i].second;
    }

    int l = 0, r = max_w + 2;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1; 
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans << endl;
}