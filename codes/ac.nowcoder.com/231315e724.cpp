// 链接: https://ac.nowcoder.com/acm/contest/120561/H
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

#define ll long long
#define MOD 998244353

ll mod_pow(ll a, ll b) {
    ll res = 1 % MOD;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void slove() {
    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    vector<ll> sdp(n + 1, 0);
    sdp[0] = 1;

    int L = 1; int cc = 0;
    for (int i = 1; i <= n; i++) {
        
        while (cc & a[i]) {
            cc ^= a[L];
            L++;
        }
        
        cc |= a[i];
        ll cu = sdp[i - 1];
        if (L > 1) {
            cu = (cu - sdp[L - 2] + MOD) % MOD;
        }

        dp[i] = cu;
        sdp[i] = (sdp[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] << "\n";
}