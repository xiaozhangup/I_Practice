// 链接: https://ac.nowcoder.com/acm/contest/120563/F
// 日期: 2026年02月07日

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

// OOOMOOMOOOOMOOOOO
// OMOOOOOOMOOOOOOOO

// OO
// OM

void slove() {
    int n; cin >> n;
    if (n <= 2) cout << n - 1 << "\n";
    else cout << n << "\n";
}

// void slove() {
//     int n; cin >> n;
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         char c = rqp[i % 4] - '0';
//         sum += c;

//         if (c == 2 && i == n - 1) {
//             sum--;
//         }
//     }

//     cout << sum - 1 << "\n";
// }