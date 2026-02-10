// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1102
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

#define int long long

void slove() {
    int n, c; cin >> n >> c;
    map<int, int> cont;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cont[a]++;
    }

    int sum = 0;
    for (auto pa : cont) {
        if (cont.find(pa.first + c) == cont.end()) continue;
        sum += pa.second * cont[pa.first + c];
    }

    cout << sum;
}