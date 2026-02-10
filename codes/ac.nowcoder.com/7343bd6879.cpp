// 链接: https://ac.nowcoder.com/acm/contest/127702/B
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
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n; cin >> n;
    vector<vector<char>> mapping(n + 2, vector<char>(n + 2));
    vector<pair<int, int>> rec;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            mapping[i][j] = c;

            if (c == '*') {
                rec.push_back({i, j});
            }
        }
    }

    int maxx = 0;
    for (auto pa : rec) {
        int co = 0;
        if (mapping[pa.first + 1][pa.second] == '*') co++;
        if (mapping[pa.first - 1][pa.second] == '*') co++;
        if (mapping[pa.first][pa.second + 1] == '*') co++;
        if (mapping[pa.first][pa.second - 1] == '*') co++;
        maxx = max(maxx, co);
    }

    if (maxx == 3) cout << "T";
    else cout << "L";

    cout << "\n";
}