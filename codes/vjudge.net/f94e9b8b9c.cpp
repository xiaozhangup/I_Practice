// 链接: https://vjudge.net/problem/OpenJ_Bailian-3414
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

    // int T = 1;
    // // cin >> T;
    // while (T--) {
    slove();
    // }
}

#define int long long

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
    int n, m;
    while(cin >> n >> m) {
        vector<int> arr(n);
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int s = 0;
        for (int i = 0; i < n; i++) {
            int w = qpow(2, n - 1 - i, m);
            int t = (arr[i] % m * w) % m;
            s = (s + t) % m;
        }

        if (n > 0 && arr[0] >= 1) {
            int f = qpow(2, arr[0] - 1, m);
            int res = (f * s) % m;
            int sub = (f - 1 + m) % m;
            cout << (res - sub + m) % m << "\n";
        } else {
            cout << s << "\n";
        }
    }
}