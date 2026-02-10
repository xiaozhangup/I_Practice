// 链接: https://vjudge.net/problem/UVA-11572
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
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n; cin >> n;
    
    int l = 0, r = 0;
    int maxl = 1;
    map<int, int> cont;
    vector<int> arr(n);

    for (r = 0; r < n; r++) {
        int m; cin >> m;
        arr[r] = m;
        cont[m]++;
        while(cont[m] > 1) {
            cont[arr[l++]]--;
        }

        maxl = max(maxl, r - l + 1);
    }

    cout << maxl << "\n";
}