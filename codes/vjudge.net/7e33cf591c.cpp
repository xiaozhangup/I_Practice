// 链接: https://vjudge.net/problem/AtCoder-abc260_e
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

vector<pair<int, int>> pas;

int f(int a) {
    
}

void slove() {
    int n, m; cin >> n >> m;
    pas = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pas[i] = {a, b};
    }

    for (int i = 1; i <= m; i++) {
        if (i != 1) cout << " ";
        cout << f(i);
    }
}