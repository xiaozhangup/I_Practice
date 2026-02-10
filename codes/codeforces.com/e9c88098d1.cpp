// 链接: https://codeforces.com/contest/2193/problem/D
// 日期: 2026年01月26日

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

map<int, int> arra;

void slove() {
    int n; cin >> n;
    arra.clear();

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        arra[a]++;
    }

    vector<int> arrb(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arrb[i];
    }

    vector<int> suma(arra.size() + 1);
    int ia = 1;
    for (auto ap : arra) {
        suma[ia] = suma[ia - 1] + ap.second;
        ia++;
    }

    int index = 0;
    ll mmax = 0;
    for (auto ap : arra) {
        index++;
        ll x = ap.first;
        ll count = suma[arra.size()] - suma[index - 1];
        
        ll level = 0;
        bool fir = true;
        for (int bp : arrb) {
            count -= bp;
            if (count > 0) level++;
            else break;
        }

        mmax = max(mmax, x * level);
    }

    cout << mmax << "\n";
}