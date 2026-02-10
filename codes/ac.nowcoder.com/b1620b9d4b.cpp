// 链接: https://ac.nowcoder.com/acm/contest/120564/G
// 日期: 2026年02月09日

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

#define int long long

int m = 0;

int f(int x) {
    int res = 1;
    while (x > 0) {
        res *= (x % 10);
        x /= 10;
    }

    return res;
}

int g(int x) {
    int res = 0;
    while (true) {
        int y = f(x);
        if (y == x) break;

        x = y;
        res++;
    }

    return res;
}

vector<int> arr;
void dfs(int ind, int len, int last, int cur) {
    if (g(cur) == 12) {
        // cout << cur << ": " << g(cur) << "\n";
        arr.push_back(cur);
    }
    // cout << cur << "\n";

    if (ind == len) return;
    for (int d = last; d <= 9; d++) {
        dfs(ind + 1, len, d, cur * 10 + d);
    }
}

void slove() {
    // int sd;
    // while (cin >> sd) {
    //     cout << f(sd);
    //     cout << "\n";
    // }
    // for (int i = 4; i <= 18; i++) {
    //     dfs(0, i, 2, 0);
    // }
    // sort(arr.begin(), arr.end());
    // for (int i : arr) {
    //     cout << i << "\n";
    // }
    cout << "336666777779999999 344444444666777777";
}