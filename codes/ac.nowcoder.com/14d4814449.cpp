// 链接: https://ac.nowcoder.com/acm/contest/127702/C
// 日期: 2026年02月08日

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
    int n; cin >> n;
    map<int, vector<int>> mapping;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        mapping[u].push_back(v);
        mapping[v].push_back(u);
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) { // ROOT
        if (mapping[i].size() > 4) {
            cout << 0;
            return;
        }
        
        if (mapping[i].size() <= 2) sum++;
    }

    cout << sum;
}