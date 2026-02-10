// 链接: https://ac.nowcoder.com/acm/contest/120562/B
// 日期: 2026年02月05日

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

map<int, vector<int>> mapping;

void slove() {
    int n; cin >> n;
    mapping.clear();
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        mapping[a].push_back(i);
        res[i] = a;
    }

    auto we = mapping.end();
    we--;
    int wr = we->first;
    int amo = we->second.size();
    for (int i = 1; i <= n; i++) {
        int cur = res[i];
        if (amo & 1) {
            if (cur == wr) cout << 1;
            else cout << 0;
        } else {
            if (cur == wr) cout << 0;
            else cout << 1;
        }
    }
    
    cout << "\n";
}