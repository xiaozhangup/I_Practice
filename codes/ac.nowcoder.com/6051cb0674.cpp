// 链接: https://ac.nowcoder.com/acm/contest/128672/C
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
#include <numeric>
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

#define ll long long

unordered_set<int> factorize(int x) {
    unordered_set<int> res;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p == 0) {
            res.insert(p);
            while (x % p == 0) x/= p;
        }
    }

    if (x > 1) {
        res.insert(x);
    }

    return res;
}

void slove() {
    int n; cin >> n;

    // vector<int> arra(n);
    // int res = 0;
    // for (int i = 0; i < n; i++) {
    //     cin >> arra[i];
    //     if (arra[i] == 1) {
    //         res++;
    //         arra[i] = 0;
    //     }
    // }

    
    // int cur = 0;
    // for (int i = 1; i < n; i++) {
    //     if (gcd(arra[i], arra[i - 1]) == 1) {
    //         cur++;
    //     } else {
    //         res += (cur + 1) / 2;
    //         cur = 0;
    //     }
    // }

    // res += (cur + 1) / 2;
    // cout << res << "\n";

    vector<unordered_set<int>> arra(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        arra[i] = factorize(a);
    }

    int res = 0;
    for (int i = 2; i <= n; i++) {
        bool any = false;
        for (int b : arra[i]) {
            if (arra[i - 1].find(b) != arra[i - 1].end()) {
                any = true;
                break;
            }
        }

        if (!any) {
            res++;
            for (int b : arra[i - 1]) {
                arra[i].insert(b);
            }
            if (i + 1 <= n) {
                for (int b : arra[i + 1]) {
                    arra[i].insert(b);
                }
            }
        }
    }

    cout << res << "\n";
}