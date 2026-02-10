// 链接: https://codeforces.com/gym/106290/problem/I
// 日期: 2026年01月30日

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

map<int, vector<int>> trees;
vector<int> weigh;

// map<int, int> mem;
int count(int source) {
    // if (mem.find(source) != mem.end()) {
        // return mem[source];
    // }

    vector<int> resd;
    queue<int> vis;
    vis.push(source);
    resd.push_back(weigh[source]);

    while (!vis.empty())
    {
        int ss = vis.front(); vis.pop();
        for (int sw : trees[ss]) {
            vis.push(sw);
            resd.push_back(weigh[sw]);
        }
    }
    
    sort(resd.begin(), resd.end());
    resd.erase(unique(resd.begin(), resd.end()), resd.end());
    // cout << "|";
    // for (int s : resd) {
    //     cout << s << " ";
    // }
    // cout << "| ";
    int res = -1;
    for (int i = 0; i < resd.size(); i++) {
        if (res + 1 == resd[i]) {
            res++;
        } else {
            break;
        }
    }
    // cout << ++res << "\n";

    // mem[source] = res;
    return ++res;
}

void slove() {
    int n; cin >> n;
    weigh = vector<int>(n + 1);
    for (int i = 2; i <= n; i++) {
        int f; cin >> f;
        trees[f].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> weigh[i];
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int w : trees[i]) {
    //         cout << w << "(" << weigh[w] << ") ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 1; i <= n; i++) {
        cout << count(i) << " ";
        // count(i);
    }

}