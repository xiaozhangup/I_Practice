// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P2043
// 日期: 2026年02月22日

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

void slove() {
    const int N = 1000000;
    vector<int> primes;
    bool vis[N + 1];

    for (int i = 2; i <= N; i++) {
        if (!vis[i]) primes.push_back(i);
        for (int p : primes) {
            if (1LL * p * i > N) break;
            vis[p * i] = true;
            if (i % p == 0) break;
        }
    }

    int n; cin >> n;
    for (int p : primes) {
        int cnt = 0;
        int t = n;
        while (t)
        {
            t /= p;
            cnt += t;
        }
        if (cnt > 0) {
            cout << p << " " << cnt << "\n";
        }
    }
}