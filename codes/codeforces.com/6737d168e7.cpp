// 链接: https://codeforces.com/contest/2205/problem/B
// 日期: 2026年02月26日

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

const int N = 1000000;
vector<int> primes;
bool vis[N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= 1e6; i++) {
        if (!vis[i]) primes.push_back(i);
        for (int p : primes) {
            if (1LL * p * i > N) break;
            vis[p * i] = true;
            if (i % p == 0) break;
        }
    }

    int T = 1;
    cin >> T;
    while (T--) {
        slove();
    }
}

#define int long long

vector<int> factorize(int x) {
    vector<int> res;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p == 0) {
            res.push_back(p);
            while (x % p == 0) x/= p;
        }
    }

    if (x > 1) {
        res.push_back(x);
    }

    return res;
}

void slove() {
    int n; cin >> n;
    auto fac = factorize(n);
    int res = 1;
    for (int i : fac) {
        res *= i;
    }
    
    cout << res << "\n";
}