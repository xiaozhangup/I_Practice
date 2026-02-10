// 链接: https://ac.nowcoder.com/acm/contest/120561/B
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

const int MOD = 998244353;
long long fact[200005];

void init_factorial(int N) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init_factorial(200000);
    int T = 1;
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n; cin >> n;
    vector<int> arra(n + 1);
    vector<int> arrb(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arra[i];
    }

    int minb = n * 2;
    for (int i = 1; i <= n; i++) {
        cin >> arrb[i];
        minb = min(minb, arrb[i]);
    }

    int lost = n;
    for (int i : arra) {
        if (i > minb) {
            lost--;
        }
    }

    cout << fact[lost] * fact[n - lost] % MOD << "\n";
}