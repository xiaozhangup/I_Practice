// 链接: https://ac.nowcoder.com/acm/contest/120561/A
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
#define MOD 998244353

vector<vector<int>> mapping = {
    {1, 2, 3, 5, 6, 7},
    {3, 6},
    {1, 3, 4, 5, 7},
    {1, 3, 4, 6, 7},
    {2, 3, 4, 6},
    {1, 2, 4, 6, 7},
    {1, 2, 4, 5, 6, 7},
    {1, 3, 6},
    {1, 2, 3, 4, 5, 6, 7},
    {1, 2, 3, 4, 6, 7}
};

void slove() {
    int c; cin >> c;
    vector<int> v(8);
    for (int i = 1; i <= 7; i++) {
        int p; cin >> p;
        v[i] = p;
    }

    vector<int> cache(9); // 1e(7 * 2)
    for (int i = 0; i <= 9; i++) {
        int re = 1;
        for (int id : mapping[i]) {
            re *= v[id];
            re %= MOD;
        }
        cache[i] = re;
    }

    for (int i = 0; i <= c; i++) {
    }
}