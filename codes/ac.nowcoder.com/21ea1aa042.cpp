// 链接: https://ac.nowcoder.com/acm/contest/120562/J
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
    // cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

map<int, vector<int>> mapping;
vector<pair<int, int>> weight; // id, weight

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

void slove() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        mapping[u].push_back(v);
        mapping[v].push_back(u);
    }

    weight.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        weight[i] = {i, mapping[i].size()};
    }
    sort(weight.begin() + 1, weight.end(), comp);
    vector<int> ans(n + 1, -1);

    // CHUNK
    unordered_map<int, vector<int>> chunked;
    vector<int> levels;
    for (int i = 1; i <= n; i++) {
        int f = weight[i].first;
        int s = weight[i].second;
        chunked[s].push_back(f);
        if (levels.size() == 0 || levels[levels.size() - 1] != s) {
            levels.push_back(s);
        }
    }

    vector<int> step(n + 1, 1e9);
    queue<int> q;
    for (int deg : levels) {
        for (int u : chunked[deg]) {
            if (step[u] != 1e9) {
                ans[u] = step[u];
            } else if (step[u] != 0) {
                step[u] = 0;
                q.push(u);
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : mapping[u]) {
                if (step[v] > step[u] + 1) {
                    step[v] = step[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << ans[i];
    }

}

// for (int i = 1; i <= n; i++) {
    
//     map<int, int> step;
//     queue<int> q;
//     vector<bool> visited(1e6 + 10, false);
//     q.push(i);
//     step[i] = 0;
//     visited[i] = true;
//     int fins = -1;

//     while (!q.empty()) {
//         if (fins != -1) break;
//         int node = q.front();
//         q.pop();

//         for (int neighbor : mapping[node]) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 q.push(neighbor);
//                 step[neighbor] = step[node] + 1;
//                 if (mapping[i].size() < mapping[neighbor].size()) {
//                     fins = step[neighbor];
//                 }
//             }
//         }
//     }
    
//     cout << fins << " ";
// }