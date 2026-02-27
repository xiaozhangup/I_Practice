// 链接: https://ac.nowcoder.com/acm/contest/128675/B
// 日期: 2026年02月27日

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

long long qpow(long long a, long long b, long long mod) {
    long long r = 1 % mod;
    while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;	
        b >>= 1;
    }
    return r;
}

void slove() {
    int n, k; cin >> n >> k;
    cout << qpow(2 * k + 1, n, 998244353);
}