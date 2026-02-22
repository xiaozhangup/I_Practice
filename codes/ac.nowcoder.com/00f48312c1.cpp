// 链接: https://ac.nowcoder.com/acm/contest/128672/D
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
    cin >> T;
    while (T--) {
        slove();
    }
}

#define int long long

void slove() {
    int n; cin >> n;
    int sum = 0, sig = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a & 1) {
            sig++;
        }
        sum += a;
    }

    cout << ((n - 1) * sum - (sig * (n - sig))) / 2 << "\n";
}