// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1434
// 日期: 2026年02月19日

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

bool comp(int a, int b) {
    return a > b;
}

int offX[] = {1, 0, -1, 0};
int offY[] = {0, 1, 0, -1};

void slove() {
    int r, c; cin >> r >> c;
    vector<vector<int>> mapping(r + 2, vector<int>(c + 2, -1));
    map<int, vector<pair<int, int>>> nodes;
    vector<int> hei;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int sr; cin >> sr;
            mapping[i][j] = sr;
            hei.push_back(sr);
            nodes[mapping[i][j]].push_back({i, j});
        }
    }

    sort(hei.begin(), hei.end(), comp);
    hei.erase(unique(hei.begin(), hei.end()), hei.end());
    int maxx = 0;
    vector<vector<int>> dp(r + 2, vector<int>(c + 2, 0));
    for (int height : hei) {
        for (auto ns : nodes[height]) {
            dp[ns.first][ns.second] = 1;
            for (int t = 0; t < 4; t++) {
                int tx = ns.first + offX[t];
                int ty = ns.second + offY[t];

                if (mapping[tx][ty] > mapping[ns.first][ns.second]) {
                    dp[ns.first][ns.second] = max(dp[ns.first][ns.second], dp[tx][ty] + 1);
                    maxx = max(maxx, dp[ns.first][ns.second]);
                }
            }
        }
    }

    cout << max(1, maxx);
}