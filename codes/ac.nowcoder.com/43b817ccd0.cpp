// 链接: https://ac.nowcoder.com/acm/contest/127703/F
// 日期: 2026年02月15日

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
    int n; cin >> n;
    string s; cin >> s;

    int dep = 0;
    int chunk = 0;

    for (char c : s) {
        if (c == '(') {
            if (dep == 0) chunk++;
            dep++;
        } else {
            dep--;
        }
    }

    cout << qpow(2, chunk, 998244353) << "\n";
}